int clockPin = 11;
int dataPin = 12;
int dataPin2 = 10;
int latchPin = 5;

boolean output[16] = { };
boolean stringComplete = false;
String command = "";
int address = -1;

void setup() {
  Serial.begin(9600);
  
  pinMode(dataPin, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);   
  
  command.reserve(200);
  
  for (int i = 0; i <= sizeof(output)/sizeof(boolean); i++) {
    output[i] = 0;
  }  
  shiftDataOut(dataPin, output);
  
  
  Serial.println("initialized");
}
     
void loop() {
  //updateShiftRegister(output);
  
  /*for (int i = 0; i <= sizeof(outputs); i++) {
    outputs[i] = 0;
  }
  for (int i = 0; i <= sizeof(outputs); i++) {
    outputs[i] = 1;
    updateShiftRegister(outputs);
    delay(10);
  }*/
  //Serial.println(analogRead(0));
  delay(100);
}

int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}


void serialEvent() {
  while (Serial.available()) {
    if (stringComplete) {
      command = "";
      stringComplete = false;
    }
    char inChar = (char)Serial.read();
    if (inChar == ':') {
      address = command.toInt();
      stringComplete = true;
    } 
    if (inChar == '\n' && address > -1) {
      boolean state = (command.toInt() == 1);
      
      Serial.println(String(address) + ";" + String(state));
      //Serial.println(command);
      stringComplete = true;
      updateShiftRegister(address, state);
      
      //Serial.print("freeRAM=");
      //Serial.println(freeRam());
      address = -1;
    }
    command += inChar;
  }
}
     
void updateShiftRegister(int address, boolean state) {
  output[address] = state;
  shiftDataOut(dataPin, output);
}
 
void shiftDataOut(uint8_t dataPin, boolean output[]) {
  int i;
  for (i = 7; i >= 0; i--)  {
    digitalWrite(dataPin, output[i]);
    digitalWrite(dataPin2, output[i+8]);            
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin,LOW);
}

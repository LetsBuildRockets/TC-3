int clockPin = 11;
int dataPins = {
  12, 10, 0, 0};
int latchPin = 9;
boolean output[16] = { 
};
boolean stringComplete = false;
String command = "";
int address = -1;

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < 4; i++) {
    pinMode(dataPin[i], OUTPUT);
  }
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);   

  command.reserve(200);

  for (int i = 0; i <= sizeof(output)/sizeof(boolean); i++) {
    output[i] = 0;
  }  
  shiftDataOut(dataPin, output);


  Serial.println("initialized");
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



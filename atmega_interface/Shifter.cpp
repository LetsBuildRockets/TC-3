#include <arduino.h>

#define clockPin 11
#define latchPin 9

int dataPin[] = {
  12, 10  };
boolean output[16] = { 
};
boolean stringComplete = false;
String command = "";
int address = -1;
class Shifter {
private:


  Shifter() {
    Serial.begin(9600);

    pinMode(dataPin[0], OUTPUT);
    pinMode(dataPin[1], OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);   

    command.reserve(200);

    for (int i = 0; i < 16; i++) {
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
    for (int i = 7; i >= 0; i--)  {
      digitalWrite(dataPin, output[i]);
      digitalWrite(dataPin2, output[i+8]);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
    }
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin,LOW);
  }

};




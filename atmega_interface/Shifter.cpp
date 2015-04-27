#include <arduino.h>

#define clockPin 11
#define latchPin 9

int dataPin[] = {
  12, 10  };
boolean output[24] = { 
};
boolean stringComplete = false;
int address = -1;
class Shifter {
private:
  Shifter() {
    pinMode(dataPin[0], OUTPUT);
    pinMode(dataPin[1], OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);   

    for (int i = 0; i < 24; i++) {
      output[i] = 0;
    }
    updateShiftRegister();


    Serial.println("initialized");
  }

  void updateShiftRegister() {
    shiftDataOut();
  }

  void shiftDataOut() {
    for (int i = 7; i >= 0; i--)  {
      digitalWrite(dataPin[0], output[i]);
      digitalWrite(dataPin[1], output[i+8]);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
    }
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin,LOW);
  }

public:
   void updateShiftRegister(int address, boolean state) {
    output[address] = state;
    shiftDataOut();
  }
};




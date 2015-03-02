
#include "Arduino.h"
#include "Wire.h"
#include "I2C.h"

int score;
boolean newScoreAvailable;

I2C::I2C() {
}

void I2C::begin(byte _address) {
  Wire.begin(_address);          // Start I2C Bus as a Slave
  Wire.onRequest(requestEvent);
  Wire.onReceive(recieveEvent);
  newScoreAvailable = false;
}

void I2C::requestEvent() {
  Wire.write(0);
}

void I2C::recieveEvent(int _length) {
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}



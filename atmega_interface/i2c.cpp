#include "Arduino.h"
#include "Wire.h"
#include "I2C.h"

byte command[8] = { 0 };

I2C::I2C() { 

}

void I2C::begin(byte _address) {
  Wire.begin(_address);
  Wire.onRequest(requestEvent);
  Wire.onReceive(recieveEvent);
}

byte* I2C::refresh() {
  byte* returnbytes = new byte[8];
  memcpy(returnbytes, command, 8);
  return returnbytes;
}

void I2C::requestEvent() {
  // Do nothing
}

void I2C::recieveEvent(int _length) {
  byte data[8] = { 0 };
  int byteCounter = 0;
  while(Wire.available() > 0) {
    data[byteCounter] = Wire.read();
    byteCounter++;
  }
  for(int i = 0; i < byteCounter; i++) { 
    command[i] = data[i];
    Serial.print(data[0]);
  }
}




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

void I2C::sendScore(int newScore) {
  if(newScore > 3) score = 3;
  else if(newScore < -3) score = -3;
  else score = newScore;
  newScoreAvailable = true;
}

void I2C::requestEvent() {
  if(newScoreAvailable) {
    I2C_writeAnything(score);
    newScoreAvailable = false;
  }
  else I2C_writeAnything(0);
}

void I2C::recieveEvent(int _length) {
  if(newScoreAvailable) {
    I2C_writeAnything(score);
    newScoreAvailable = false;
  }
  else I2C_writeAnything(0);
}



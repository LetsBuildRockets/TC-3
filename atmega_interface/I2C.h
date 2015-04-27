#ifndef I2C_h
#define I2C_h

#include "Arduino.h"

class I2C {
public:
  I2C();
  byte* refresh();
  void begin(byte _address);
  static void requestEvent();
  static void recieveEvent(int _length);
};
#endif


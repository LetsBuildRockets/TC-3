#ifndef I2C_h
#define I2C_h

#include "Arduino.h"

template <typename T> unsigned int I2C_writeAnything (const T& value) {
  return  Wire.write((byte *) &value, sizeof (value));
}  


class I2C {
public:
  I2C();
  void begin(byte _address);
  void sendScore(int newScore);
  static void requestEvent();
  static void recieveEvent(int _length);
};
#endif


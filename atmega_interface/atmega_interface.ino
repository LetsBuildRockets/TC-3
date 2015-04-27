// TODO: i2c for devices
// TODO: i2c to computer
// TODO: shift out for actions
// TODO: d latch

#include <Wire.h>
#include "I2C.h"

const int I2C_ADDR = 0x40;

I2C i2c;

void setup() {
  i2c.begin(I2C_ADDR);
  
}

void loop() {
  
  
}


int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

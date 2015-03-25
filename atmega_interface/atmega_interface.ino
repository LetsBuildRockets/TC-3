// TODO: i2c for devices
// TODO: i2c to computer
// TODO: shift out for actions
// TODO: d latch

#include <Wire.h>

#define I2C_ADDR = 0x40

void setup() {
  
  
}

void loop() {
  
  
}


int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

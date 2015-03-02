#include <Arduino.h>
#include <Wire.h>

class I2C {
private:
  int addr;

  void requestEvent() {
    Wire.write("hello ");
  }
public:
  I2C(const int addr_new) {
    addr = dddr_new;
    Wire.begin(addr);
    Wire.onRequest(requestEvent);
  }
};






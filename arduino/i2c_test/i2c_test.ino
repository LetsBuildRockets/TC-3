#include <Wire.h>

int number = 0;
int state = 0;

void setup() {
  Serial.begin(9600); 
  Wire.begin();


  Wire.beginTransmission(0x49);
  Wire.write(B00000001);
  Wire.write(B01000100);
  Wire.write(B10000011); // 0 000 010 0 100 0 0 0 00
  Wire.endTransmission();
}

void loop() {
  

  Wire.beginTransmission(0x49);
  Wire.write(B00000001);
  Wire.write(B01000000);
  Wire.write(B10000011); // 0 000 010 0 100 0 0 0 00
  Wire.endTransmission();
  Wire.beginTransmission(0x49);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(0x49, 2, true);
  if(Wire.available()) {
    long value = 256 * Wire.read();
    value += Wire.read();
    Serial.print("0:");
    Serial.println((value/32768.0f)*5.0f);
  }
  Wire.endTransmission(); 
 delay(100);
  Wire.beginTransmission(0x49);
  Wire.write(B00000001);
  Wire.write(B01010000);
  Wire.write(B10000011); // 0 000 010 0 100 0 0 0 00
  Wire.endTransmission();
  Wire.beginTransmission(0x49);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(0x49, 2, true);
  if(Wire.available()) {
    long value = 256 * Wire.read();
    value += Wire.read();
    Serial.print("1:");
    Serial.println((value/32768.0f)*5.0f);
  }
  Wire.endTransmission(); 
  
  
  delay(50);
}

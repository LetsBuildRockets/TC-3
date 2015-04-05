#include <Wire.h>
 
void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);         // start serial for output
  Serial.println("hello!");
}
 
void loop() {
  delay(100);
}
 
void receiveEvent(int howMany) {
  int a=0;
  while(Wire.available()>0)
  {
     Serial.println(Wire.read());
  }
  Wire.write(1);
}

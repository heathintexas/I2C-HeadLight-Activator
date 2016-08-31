#include <Wire.h>

bool rampUp = true;

void setup()
{
  Wire.begin(); // join i2c bus
}

void loop()
{
  Wire.beginTransmission(0x4E); // transmit to device 0x4E aka Frontlight
  Wire.write(0);             // reserved 0
  if (rampUp) {
    Wire.write(0);             // outside light 0 - 31
    Wire.write(255);            // instide light 0 -255
  } else {
    Wire.write(31);             // outside light 0 - 31
    Wire.write(0);            // instide light 0 -255
  }
  Wire.write(0);              //reserved 0
  Wire.write(100);            // dim time 0 - 255 time 10 ms steps
  Wire.endTransmission();     // stop transmitting

  rampUp = !rampUp;
  delay(1000);
}

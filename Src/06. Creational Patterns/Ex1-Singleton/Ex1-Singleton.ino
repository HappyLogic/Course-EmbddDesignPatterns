#include "Motor.h"

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Motor::getInstance()->start();
  delay(1000);
  Motor::getInstance()->stop();
  delay(1000);
}

#include "Motor.h"

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  theMotor.start();
  delay(1000);

  theMotor.stop();
  delay(1000);
}

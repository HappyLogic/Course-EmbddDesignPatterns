#include "MotorControl.h"


void setup()
{
  setupMotorPins();
}

void loop()
{
  updateMotorState();
  delay(100);
}

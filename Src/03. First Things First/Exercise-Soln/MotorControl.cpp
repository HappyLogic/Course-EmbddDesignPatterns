#include "MotorControl.h"
#include <Arduino.h>

void setupMotorPins()
{
  pinMode(MOTOR_SWITCH, INPUT);
  pinMode(MOTOR_DRIVE, OUTPUT);
}

void updateMotorState()
{
  if (digitalRead(MOTOR_SWITCH))
  {
    digitalWrite(MOTOR_DRIVE, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_DRIVE, LOW);
  }
}

#include "Motor.h"
#include <Arduino.h>

Motor::Motor()
{
  //- Initializing the motor
}
void Motor::start()
{
  Serial.println("Motor started");
}
void Motor::stop()
{
  Serial.println("Motor stopped");
}

Motor theMotor;


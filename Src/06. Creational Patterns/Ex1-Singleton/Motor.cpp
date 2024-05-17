#include "Motor.h"
#include <Arduino.h>

Motor* Motor::instance = nullptr;

Motor* Motor::getInstance()
{
  if (instance == nullptr)
  {
    instance = new Motor();
  }

  return instance;
}

Motor::Motor()
{
  Serial.println("Motor instance created");
}
void Motor::start()
{
  Serial.println("Motor started");
}
void Motor::stop()
{
  Serial.println("Motor stopped");
}

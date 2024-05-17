#include "AnalogIn.h"

float AnalogInNormal::readVoltage()
{
  Serial.println("AnalogInNormal - Reading Voltage");
  return 0;
}

float AnalogInAverage::readVoltage()
{
  Serial.println("AnalogInAverage - Reading Voltage");
  return 0;
}

//- 
//- Factory
//- 
AnalogIn* getAnalogReader(uint8_t pin)
{
  if (pin <= 5)
  {
    return new AnalogInNormal();
  }
  else
  {
    return new AnalogInAverage();
  }
}

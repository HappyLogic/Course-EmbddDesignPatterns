#include "VoltageReader.h"
#include <Arduino.h>

//- 
//- SimpleVoltageReader
//- 
SimpleVoltageReader::SimpleVoltageReader(int pin)
  : m_iPin(pin)
{
  pinMode(pin, INPUT);
}

float SimpleVoltageReader::getVoltage()
{
  return analogRead(m_iPin) * (5.0f / 1024);
}

//- 
//- AveragingVoltageReader
//- 
AveragingVoltageReader::AveragingVoltageReader(VoltageReader* vr, int readings)
  : m_pInternalVR(vr), m_iReadings(readings) {}

float AveragingVoltageReader::getVoltage()
{
  float sum = 0.0f;

  for (int i = 0; i < m_iReadings; i++)
  {
    sum += m_pInternalVR->getVoltage();
  }

  return sum / m_iReadings;
}

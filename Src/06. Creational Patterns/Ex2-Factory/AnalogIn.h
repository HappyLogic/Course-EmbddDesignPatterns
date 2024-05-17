#ifndef _MY_FACTORY_ANALOGIN_H_
#define _MY_FACTORY_ANALOGIN_H_

#include <Arduino.h>

class AnalogIn
{
  public:
    virtual float readVoltage() = 0;
};

class AnalogInNormal : public AnalogIn
{
  public:
    float readVoltage() override;
};

class AnalogInAverage : public AnalogIn
{
  public:
    float readVoltage() override;
};


AnalogIn* getAnalogReader(uint8_t);




#endif
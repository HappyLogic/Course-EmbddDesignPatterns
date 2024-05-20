#ifndef _MY_DECORATOR_VOLTAGEREADER_H_
#define _MY_DECORATOR_VOLTAGEREADER_H_

class VoltageReader
{
  public:
    virtual float getVoltage() = 0;
};

class SimpleVoltageReader : public VoltageReader
{
  public:
    SimpleVoltageReader(int pin);
    float getVoltage() override;

  private:
    int m_iPin;
};

class AveragingVoltageReader : public VoltageReader
{
  public:
    AveragingVoltageReader(VoltageReader*, int readings);
    float getVoltage() override;

  private:
    VoltageReader* m_pInternalVR;
    int m_iReadings;
};




#endif
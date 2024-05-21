#ifndef _MY_STRATEGYPATTERN_ANALOGREADER_H_
#define _MY_STRATEGYPATTERN_ANALOGREADER_H_

#include "AnalogCalcStrategies.h"
#include "Arduino.h"

class AnalogReader
{
  public:
    AnalogReader(int pin, AnalogCalcStrategy* strategy, int totalSamples)
     : m_iPin(pin), m_pStrategy(strategy), m_iTotalSamples(totalSamples), m_iCurrentSampleIndex(0), m_fCurrentValue(0.f)
    {
      m_aSamples = new float[totalSamples];
      pinMode(pin, INPUT);
    }

    float GetReading() const { return m_fCurrentValue; }

    void Update()
    {
      m_aSamples[m_iCurrentSampleIndex++] = analogRead(m_iPin) * (5.0f / 1024);

      if (m_iCurrentSampleIndex >= m_iTotalSamples)
      {
        m_iCurrentSampleIndex = 0;
        m_fCurrentValue = m_pStrategy->Calculate(m_aSamples, m_iTotalSamples);
      }
    }

  private:
    int m_iPin;
    AnalogCalcStrategy* m_pStrategy;
    int m_iTotalSamples, m_iCurrentSampleIndex;
    float m_fCurrentValue;
    float* m_aSamples;
};




#endif
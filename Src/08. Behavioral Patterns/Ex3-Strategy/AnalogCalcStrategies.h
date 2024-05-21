#ifndef _MY_STRATEGYPATTERN_ANALOGCALCSTRATEGIES_H_
#define _MY_STRATEGYPATTERN_ANALOGCALCSTRATEGIES_H_

class AnalogCalcStrategy
{
  public: virtual float Calculate(const float *data, const int size) = 0;
};

class AveragingAnalogCalcStrategy : public AnalogCalcStrategy
{
  public:
    float Calculate(const float *data, const int size) override
    {
      float sum = 0.f;

      for (int i = 0; i < size; i++)
      {
        sum += data[i];
      }

      return sum / size;
    }
};




#endif
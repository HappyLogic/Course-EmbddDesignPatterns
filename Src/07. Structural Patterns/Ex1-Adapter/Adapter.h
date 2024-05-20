#ifndef _MY_ADAPTERPATTERN_ADAPTER_H_
#define _MY_ADAPTERPATTERN_ADAPTER_H_


class Adapter
{
  public:
    virtual void delayMilliseconds(int ms) = 0;
    virtual void printMessage(const char*) = 0;
};




#endif
#ifndef _MY_ADAPTERPATTERN_ADAPTERARDUINO_H_
#define _MY_ADAPTERPATTERN_ADAPTERARDUINO_H_

#include "Adapter.h"
#include <Arduino.h>

class AdapterArduino : public Adapter
{
  public:
    void delayMilliseconds(int ms) override
    {
      delay(ms);
    }

    void printMessage(const char* msg) override
    {
      Serial.println(msg);
    }
};




#endif
#include "AnalogIn.h"


AnalogIn* in1 = nullptr;
AnalogIn* in2 = nullptr;

void setup()
{
  Serial.begin(115200);

  in1 = getAnalogReader(1);
  in2 = getAnalogReader(8);
}

void loop()
{
  in1->readVoltage();
  in2->readVoltage();
  
  delay(1000);
}

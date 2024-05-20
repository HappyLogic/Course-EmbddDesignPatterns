#include "VoltageReader.h"

SimpleVoltageReader simpleVR(A1);
AveragingVoltageReader avgVR(&simpleVR, 20);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.print("Conversion: Simple Voltage = ");
  Serial.print(simpleVR.getVoltage());
  Serial.print(", Averaging Voltage = ");
  Serial.print(avgVR.getVoltage());
  Serial.println("");
  delay(1000);
}

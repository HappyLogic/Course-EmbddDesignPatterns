#include "AnalogReader.h"
#include "AnalogCalcStrategies.h"

AveragingAnalogCalcStrategy strategy;
AnalogReader analogReader(A2, &strategy, 50);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  analogReader.Update();
  
  static unsigned long lastPrintMillis = 0;
  if ((millis() - lastPrintMillis) >= 1500)
  {
    Serial.print("Current value = ");
    Serial.print(analogReader.GetReading());
    Serial.println("");

    lastPrintMillis = millis();
  }
}

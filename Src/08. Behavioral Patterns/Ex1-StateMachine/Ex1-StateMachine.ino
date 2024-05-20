#include "StateMachine.h"

StateMachine sm;

void setup()
{
  Serial.begin(115200);
  sm.Start();
}

void loop()
{
  sm.Update();
}

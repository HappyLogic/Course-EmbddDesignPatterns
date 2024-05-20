#include "App.h"
#include "Adapter-Arduino.h"

App* app = nullptr;
AdapterArduino* adapter = nullptr;

void setup()
{
  Serial.begin(115200);

  adapter = new AdapterArduino();
  app = new App(adapter);
}

void loop()
{
  app->Run();
}

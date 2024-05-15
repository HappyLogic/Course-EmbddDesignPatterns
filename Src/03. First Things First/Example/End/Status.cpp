#include "Status.h"
#include <Arduino.h>

void setupStatusPin()
{
  pinMode(STATUS_LED, OUTPUT);
}

void blinkStatusPin()
{
  digitalWrite(STATUS_LED, HIGH);
  delay(1000);
  
  digitalWrite(STATUS_LED, LOW);
  delay(1000);
}
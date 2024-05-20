#ifndef _MY_OBSERVERPATTERN_OBSERVER_H_
#define _MY_OBSERVERPATTERN_OBSERVER_H_

#include <Arduino.h>

enum class Event { Event1, Event2 };

class Observer
{
  public: virtual void EventOccurred(Event event, float data) = 0;
};

class SimpleObserver : public Observer
{
  public:
    SimpleObserver(const char* name) : m_sName(name) {}

    void EventOccurred(Event event, float data) override
    {
      Serial.print(m_sName);
      Serial.print(" -- ");

      switch (event)
      {
        case Event::Event1: Serial.print("Event1"); break;
        case Event::Event2: Serial.print("Event2"); break;
        default: Serial.print("UnknownEvent"); break;
      }

      Serial.print(" received with data ");
      Serial.print(data);
      Serial.println(".");
    }

  private:
    const char* m_sName;
};




#endif
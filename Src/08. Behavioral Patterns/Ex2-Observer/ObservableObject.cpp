#include "ObservableObject.h"
#include <Arduino.h>

ObservableObject::ObservableObject()
{
  for (int i = 0; i < MAX_OBSERVERS; i++)
    m_aObservers[i] = nullptr;
}

void ObservableObject::RegisterObserver(Observer* observer)
{
  for (int i = 0; i < MAX_OBSERVERS; i++)
  {
    if (m_aObservers[i] == nullptr)
    {
      m_aObservers[i] = observer;
      return;
    }
  }
}

void ObservableObject::UnregisterObserver(Observer* observer)
{
  for (int i = 0; i < MAX_OBSERVERS; i++)
  {
    if (m_aObservers[i] == observer)
    {
      m_aObservers[i] = nullptr;
      return;
    }
  }
}

void ObservableObject::Update()
{
  static unsigned long lastUpdate = 0;
  static Event event = Event::Event1;

  unsigned long elapsedMillis = millis() - lastUpdate;

  if (elapsedMillis >= 1000)
  {
    RaiseEvent(event, millis() / 1000.0f);
    lastUpdate = millis();

    if (event == Event::Event1)
      event = Event::Event2;
    else
      event = Event::Event1;
  }
}

void ObservableObject::RaiseEvent(Event event, float data)
{
  for (int i = 0; i < MAX_OBSERVERS; i++)
  {
    if (m_aObservers[i] != nullptr)
    {
      m_aObservers[i]->EventOccurred(event, data);
    }
  }
}

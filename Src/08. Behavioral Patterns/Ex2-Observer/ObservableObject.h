#ifndef _MY_OBSERVERPATTERN_OBSERVABLEOBJECT_H_
#define _MY_OBSERVERPATTERN_OBSERVABLEOBJECT_H_

#include "Observer.h"

#define MAX_OBSERVERS    10

class ObservableObject
{
  public:
    ObservableObject();

    void RegisterObserver(Observer*);
    void UnregisterObserver(Observer*);

    void Update();

  private:
    Observer* m_aObservers[MAX_OBSERVERS];

    void RaiseEvent(Event event, float data);
};




#endif
#include "Observer.h"
#include "ObservableObject.h"

SimpleObserver so1("Observer 1"), so2("Observer 2"), so3("Observer 3");
ObservableObject observable;

void setup()
{
  Serial.begin(115200);

  observable.RegisterObserver(&so1);
  observable.RegisterObserver(&so2);
  observable.RegisterObserver(&so3);
}

void loop()
{
  observable.Update();
}

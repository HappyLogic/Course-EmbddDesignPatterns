#ifndef _MY_ADAPTERPATTERN_APP_H_
#define _MY_ADAPTERPATTERN_APP_H_

#include "Adapter.h"

class App
{
  public:
    App(Adapter* adapter)
    {
      m_pAdapter = adapter;
    }

    void Run()
    {
      while (1)
      {
        m_pAdapter->printMessage("Hello From App ...");
        m_pAdapter->delayMilliseconds(2000);
      }
    }

  private:
    Adapter* m_pAdapter;
};




#endif
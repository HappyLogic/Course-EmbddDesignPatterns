#ifndef _MY_SINGLETON_MOTOR_H_
#define _MY_SINGLETON_MOTOR_H_


class Motor
{
  public:
    static Motor* getInstance();

    void start();
    void stop();

  private:
    Motor();
    static Motor *instance;
};




#endif
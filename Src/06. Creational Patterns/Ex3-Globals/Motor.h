#ifndef _MY_GLOBAL_MOTOR_H_
#define _MY_GLOBAL_MOTOR_H_


class Motor
{
  public:
    Motor();
    void start();
    void stop();
};

extern Motor theMotor;


#endif
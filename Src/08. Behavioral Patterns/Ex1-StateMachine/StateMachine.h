#ifndef _MY_STATEMACHINEPATTERN_STATEMACHINE_H_
#define _MY_STATEMACHINEPATTERN_STATEMACHINE_H_

enum class State
{
  NONE,
  Start, StateX, StateY, Stopped
};

class StateMachine
{
  public:
    StateMachine();

    void Start();
    void Update();

  private:
    State m_eCurrentState;
    unsigned long m_ulTransitionedTime;

    State GetNextState(unsigned long msecElapsed);

    void HandleState();
    void HandleStateTransition(State last, State next);
};




#endif
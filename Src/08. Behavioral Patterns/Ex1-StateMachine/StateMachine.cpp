#include "StateMachine.h"
#include <Arduino.h>

StateMachine::StateMachine()
{
  m_eCurrentState = State::NONE;
  m_ulTransitionedTime = 0;
}

void StateMachine::Start()
{
  m_eCurrentState = State::Start;
  m_ulTransitionedTime = millis();

  HandleStateTransition(State::NONE, m_eCurrentState);
}

void StateMachine::Update()
{
  HandleState();

  State nextState = GetNextState(millis() - m_ulTransitionedTime);

  if (nextState != m_eCurrentState)
  {
    HandleStateTransition(m_eCurrentState, nextState);

    m_eCurrentState = nextState;
    m_ulTransitionedTime = millis();
  }
}

State StateMachine::GetNextState(unsigned long msecElapsed)
{
  State nextState = m_eCurrentState;

  switch (m_eCurrentState)
  {
    case State::NONE:     nextState = State::Start;    break;
    case State::Start:    nextState = State::StateX;   break;
    case State::Stopped:  /*Nothing required here*/    break;

    case State::StateX:
      if (msecElapsed >= 2000)
      {
        nextState = State::StateY;
      }
      break;

    case State::StateY:
      if (msecElapsed >= 4000)
      {
        nextState = State::StateX;
      }
      break;
  }

  return nextState;
}

void StateMachine::HandleState()
{
  switch (m_eCurrentState)
  {
    case State::NONE:      /* Handling logic*/    break;
    case State::Start:     /* Handling logic*/    break;
    case State::StateX:    /* Handling logic*/    break;
    case State::StateY:    /* Handling logic*/    break;
    case State::Stopped:   /* Handling logic*/    break;
  }
}

static void PrintState(State state)
{
  switch (state)
  {
    case State::NONE:         Serial.print("NONE");           break;
    case State::Start:        Serial.print("Start");          break;
    case State::StateX:       Serial.print("StateX");         break;
    case State::StateY:       Serial.print("StateY");         break;
    case State::Stopped:      Serial.print("Stopped");        break;
  }
}

void StateMachine::HandleStateTransition(State last, State next)
{
  Serial.print("Going from ");
  PrintState(last);
  Serial.print(" to ");
  PrintState(next);
  Serial.println(".");
}

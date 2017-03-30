#pragma once

#include "IState.h"
class Elevator
{
public:
    Elevator();
    ~Elevator();

public:
    void Action(ElevatorButtonAction act);
    ElevatorState curr_state() { return istate_->curr_state(); }

private:
    IState *istate_{nullptr};
};


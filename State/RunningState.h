#pragma once
#include "IState.h"
class RunningState :
    public IState
{
public:
    RunningState();
    ~RunningState();

public:
    ElevatorState Open() override;
    ElevatorState Close() override;
    ElevatorState curr_state() const override { return ElevatorState::kRunning; };

};


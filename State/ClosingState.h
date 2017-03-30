#pragma once
#include "IState.h"
class ClosingState :
    public IState
{
public:
    ClosingState();
    ~ClosingState();

public:
    ElevatorState Open() override;
    ElevatorState Close() override;
    ElevatorState curr_state() const override { return ElevatorState::kStopClosing; };

};


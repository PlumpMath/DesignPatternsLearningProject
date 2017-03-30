#pragma once
#include "IState.h"
class ClosedState : public IState
{
public:
    ClosedState();
    ~ClosedState();

public:
    ElevatorState Open() override;
    ElevatorState Close() override;

    ElevatorState curr_state() const override { return ElevatorState::kStopClosed; };
};


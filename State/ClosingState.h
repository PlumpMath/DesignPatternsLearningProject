#pragma once
#include "IState.h"
class ClosingState :
    public IState
{
public:
    ClosingState();
    ~ClosingState();

public:
    ElevatorState Handle(ElevatorButtonAction act) override;
    ElevatorState curr_state() const override { return ElevatorState::kStopClosing; };

};


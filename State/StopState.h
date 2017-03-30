#pragma once
#include "IState.h"
class StopState : public IState
{
public:
    StopState();
    ~StopState();

public:
    ElevatorState Handle(ElevatorButtonAction act) override;
    ElevatorState curr_state() const override { return ElevatorState::kStop; };
};


#pragma once
#include "IState.h"
class OpeningState :
    public IState
{
public:
    OpeningState();
    ~OpeningState();

public:
    ElevatorState Handle(ElevatorButtonAction act) override;
    ElevatorState curr_state() const override { return ElevatorState::kStopOpening; };

};


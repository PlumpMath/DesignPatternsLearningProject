#pragma once
#include "IState.h"
class OpeningState :
    public IState
{
public:
    OpeningState();
    ~OpeningState();

public:
    ElevatorState Open() override;
    ElevatorState Close() override;
    ElevatorState curr_state() const override { return ElevatorState::kStopOpening; };

};


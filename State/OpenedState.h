#pragma once

#include "IState.h"
class OpenedState :
    public IState
{
public:
    OpenedState();
    ~OpenedState();

public:
    ElevatorState Open() override;
    ElevatorState Close() override;
    ElevatorState curr_state() const override { return ElevatorState::kStopOpened; };

};


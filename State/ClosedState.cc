#include "stdafx.h"
#include "ClosedState.h"


ClosedState::ClosedState()
{
}


ClosedState::~ClosedState()
{
}

ElevatorState ClosedState::Open() {
    //TODO: Do something to open the door

    return ElevatorState::kStopOpening;
}

ElevatorState ClosedState::Close() {
    return curr_state();
}
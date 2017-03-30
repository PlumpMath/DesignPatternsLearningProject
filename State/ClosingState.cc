#include "stdafx.h"
#include "ClosingState.h"


ClosingState::ClosingState()
{
}


ClosingState::~ClosingState()
{
}

ElevatorState ClosingState::Open() {
    //TODO: Do something to open the door

    return ElevatorState::kStopOpening;
}

ElevatorState ClosingState::Close() {
    return curr_state();
}
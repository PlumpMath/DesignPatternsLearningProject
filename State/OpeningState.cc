#include "stdafx.h"
#include "OpeningState.h"


OpeningState::OpeningState()
{
}


OpeningState::~OpeningState()
{
}


ElevatorState OpeningState::Open() {
    return curr_state();
}

ElevatorState OpeningState::Close() {
    //TODO: Do something to close the door

    return ElevatorState::kStopClosing;
}
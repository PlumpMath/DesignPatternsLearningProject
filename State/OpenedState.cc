#include "stdafx.h"
#include "OpenedState.h"


OpenedState::OpenedState()
{
}


OpenedState::~OpenedState()
{
}

ElevatorState OpenedState::Open() {
    //ignored
    return curr_state();
}
ElevatorState OpenedState::Close() {
    //TODO: Do something to close the door

    return ElevatorState::kStopClosing;
}
#include "stdafx.h"
#include "StopState.h"


StopState::StopState()
{
}


StopState::~StopState()
{
}

ElevatorState StopState::Open() {
    //TODO: Do something to open the door

    return ElevatorState::kStopOpening;
}

ElevatorState StopState::Close() {
    return curr_state();
}
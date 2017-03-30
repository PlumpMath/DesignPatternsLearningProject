#include "stdafx.h"
#include "RunningState.h"


RunningState::RunningState()
{
}


RunningState::~RunningState()
{
}

ElevatorState RunningState::Open() {
    return curr_state();
}

ElevatorState RunningState::Close() {
    return curr_state();
}
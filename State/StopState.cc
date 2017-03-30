#include "stdafx.h"
#include "StopState.h"


StopState::StopState()
{
}


StopState::~StopState()
{
}

ElevatorState StopState::Handle(ElevatorButtonAction act) {
    ElevatorState new_state = curr_state();
    switch (act) {
    case ElevatorButtonAction::kClosePressed:
        //don't need to do anything
        break;
    case ElevatorButtonAction::kOpenPressed:
        //TODO: Do something to open the door
        
        //switch to next state
        new_state = ElevatorState::kStopOpening;
        break;
    default:
        assert(0);
        break;
    }

    return new_state;
}
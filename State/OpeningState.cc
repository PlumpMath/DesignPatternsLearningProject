#include "stdafx.h"
#include "OpeningState.h"


OpeningState::OpeningState()
{
}


OpeningState::~OpeningState()
{
}

ElevatorState OpeningState::Handle(ElevatorButtonAction act) {
    ElevatorState new_state = curr_state();
    switch (act) {
    case ElevatorButtonAction::kClosePressed:
        //TODO: Do something to close elevator

        //switch state
        new_state = ElevatorState::kStopClosing;
        break;
    case ElevatorButtonAction::kOpenPressed:
        //ignore 
        break;
    default:
        assert(0);
        break;
    }

    return new_state;

}
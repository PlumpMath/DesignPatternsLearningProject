#include "stdafx.h"
#include "ClosingState.h"


ClosingState::ClosingState()
{
}


ClosingState::~ClosingState()
{
}

ElevatorState ClosingState::Handle(ElevatorButtonAction act) {
    ElevatorState new_state = curr_state();
    switch (act) {
    case ElevatorButtonAction::kClosePressed:
        //ignore
        break;
    case ElevatorButtonAction::kOpenPressed:
        //TODO: Do something to open elevator

        //switch state
        new_state = ElevatorState::kStopOpening;
        break;
    default:
        assert(0);
        break;
    }

    return new_state;

}

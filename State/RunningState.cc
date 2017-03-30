#include "stdafx.h"
#include "RunningState.h"


RunningState::RunningState()
{
}


RunningState::~RunningState()
{
}

ElevatorState RunningState::Handle(ElevatorButtonAction act) {
    ElevatorState new_state = curr_state();
    switch (act) {
    case ElevatorButtonAction::kClosePressed:
    case ElevatorButtonAction::kOpenPressed:
        //ignore all actions
        break;
    default:
        assert(0);
        break;
    }

    return new_state;

}
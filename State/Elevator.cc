#include "stdafx.h"
#include "Elevator.h"
#include "StopState.h"
#include "RunningState.h"
#include "OpeningState.h"
#include "ClosingState.h"
using namespace std;

Elevator::Elevator()
{
    istate_ = new StopState();
}


Elevator::~Elevator()
{
    if (istate_) {
        delete istate_;
    }
}

void Elevator::Action(ElevatorButtonAction act) {
    assert(istate_);
    ElevatorState next_state = istate_->Handle(act);

    if (next_state != istate_->curr_state()) {
        delete istate_;
        istate_ = nullptr;

        switch (next_state) {
        case ElevatorState::kRunning:
            istate_ = new RunningState();
            break;
        case ElevatorState::kStop:
            istate_ = new StopState();
            break;
        case ElevatorState::kStopClosing:
            istate_ = new ClosingState();
            break;
        case ElevatorState::kStopOpening:
            istate_ = new OpeningState();
            break;
        default:
            //cout << "Not implemented" << endl;
            break;
        }
    }
}
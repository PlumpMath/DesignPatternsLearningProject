#include "stdafx.h"
#include "ElevatorContext.h"
#include "StopState.h"
#include "RunningState.h"
#include "OpeningState.h"
#include "ClosingState.h"
using namespace std;

ElevatorContext::ElevatorContext()
{
    istate_ = new StopState();

    actions_.insert({ ElevatorButtonAction::kOpenPressed, &IState::Open });
    actions_.insert({ ElevatorButtonAction::kClosePressed, &IState::Close });
}


ElevatorContext::~ElevatorContext()
{
    if (istate_) {
        delete istate_;
    }
}

void ElevatorContext::Action(ElevatorButtonAction act) {
    assert(istate_);

    IStateFunc_Action func = actions_[act];
    ElevatorState next_state = (istate_->*func)();
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
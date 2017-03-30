#include "stdafx.h"
#include "ElevatorContext.h"
#include "StopState.h"
#include "RunningState.h"
#include "OpeningState.h"
#include "ClosingState.h"
using namespace std;

ElevatorContext::ElevatorContext() : ElevatorContext(0, 1) {

}

ElevatorContext::ElevatorContext(int min_floor, int max_floor) :
    kMaxFloor(max_floor), kMinFloor(min_floor), curr_floor_(min_floor)
{
    assert(max_floor > min_floor);

    istates_map_.insert({ ElevatorState::kStop, new StopState() });
    istates_map_.insert({ ElevatorState::kStopClosing, new ClosingState() });
    istates_map_.insert({ ElevatorState::kStopOpening, new OpeningState() });
    istates_map_.insert({ ElevatorState::kRunning, new RunningState() });
    istate_ = istates_map_[ElevatorState::kStop];   //initialize with kStop

    actions_map_.insert({ ElevatorButtonAction::kOpenPressed, &IState::Open });
    actions_map_.insert({ ElevatorButtonAction::kClosePressed, &IState::Close });
}


ElevatorContext::~ElevatorContext()
{
    istate_ = nullptr;
    for (auto &it : istates_map_) {
        delete it.second;
    }
    istates_map_.clear();

    actions_map_.clear();
}

void ElevatorContext::Action(ElevatorButtonAction act) {
    assert(istate_);

    IStateFunc_Action func = actions_map_[act];
    ElevatorState next_state = (istate_->*func)();
    if (next_state != istate_->curr_state()) {
        istate_ = istates_map_[next_state];
    }
}
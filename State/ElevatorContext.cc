#include "stdafx.h"
#include "ElevatorContext.h"
#include "ClosedState.h"
#include "RunningState.h"
#include "OpeningState.h"
#include "ClosingState.h"
#include "OpenedState.h"
using namespace std;

ElevatorContext::ElevatorContext() : ElevatorContext(0, 1) {

}

ElevatorContext::ElevatorContext(int min_floor, int max_floor) :
    kMaxFloor(max_floor), kMinFloor(min_floor), curr_floor_(min_floor)
{
    assert(max_floor > min_floor);

    istates_map_.insert({ ElevatorState::kStopClosed, new ClosedState() });
    istates_map_.insert({ ElevatorState::kStopOpened, new OpenedState() });
    istates_map_.insert({ ElevatorState::kStopClosing, new ClosingState() });
    istates_map_.insert({ ElevatorState::kStopOpening, new OpeningState() });
    istates_map_.insert({ ElevatorState::kRunning, new RunningState() });
    istate_ = istates_map_[ElevatorState::kStopClosed];   //initialize with kStop

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

bool ElevatorContext::Action(ElevatorButtonAction act) {
    assert(istate_);

    IStateFunc_Action func = actions_map_[act];
    ElevatorState next_state = (istate_->*func)();
    if (next_state != istate_->curr_state()) {
        istate_ = istates_map_[next_state];
    }
    
    return true;
}
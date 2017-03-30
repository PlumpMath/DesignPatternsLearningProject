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
    if (engine_) {
        delete engine_;
    }

    istate_ = nullptr;
    for (auto &it : istates_map_) {
        delete it.second;
    }
    istates_map_.clear();

    actions_map_.clear();
}

void ElevatorContext::PowerOn() {
    engine_on_ = true;
    engine_ = new thread(EngineProc, this);
}
void ElevatorContext::PowerOff() {
    engine_on_ = false;
    actions_cond_.notify_all();
    engine_->join();
}

void ElevatorContext::PushAction(ElevatorButtonAction act) {
    lock_guard<mutex> lg(actions_queue_mutex_);
    
    bool notify = false;
    if (actions_queue_.empty()) {
        notify = true;
    }

    actions_queue_.push(act);

    if (notify) {
        actions_cond_.notify_all();
    }
}
void ElevatorContext::WaitAction() {
    unique_lock<mutex> lg(actions_queue_mutex_);
    actions_cond_.wait(lg);
}
bool ElevatorContext::PopAction(ElevatorButtonAction& act) {
    lock_guard<mutex> lg(actions_queue_mutex_);
    if (!actions_queue_.empty()) {
        act = actions_queue_.front();
        actions_queue_.pop();
        return true;
    }
    return false;
}
size_t ElevatorContext::ActionsQueueSize() {
    lock_guard<mutex> lg(actions_queue_mutex_);
    return actions_queue_.size();
}

void ElevatorContext::EngineProc(ElevatorContext* param) {
    assert(nullptr != param);
    ElevatorContext* thisEv = param;

    //for STATE output
    map<ElevatorState, string> ev_state_map;
    ev_state_map[ElevatorState::kStopClosed] = "CLOSED";
    ev_state_map[ElevatorState::kStopOpened] = "OPENED"
    ev_state_map[ElevatorState::kStopClosing] = "CLOSING";
    ev_state_map[ElevatorState::kStopOpening] = "OPENING";
    ev_state_map[ElevatorState::kRunning] = "RUNNING";

    cout << "Init State: " << ev_state_map[thisEv->curr_state()] << ", Floor: " << thisEv->curr_floor() << endl;
    while (thisEv->engine_on()) {

        ElevatorButtonAction act;
        if (!thisEv->PopAction(act)) {
            // wait condition until actions in
            //this_thread::sleep_for(std::chrono::milliseconds(1000));
            thisEv->WaitAction();
            continue;
        }

        thisEv->Action(act);
        cout << ev_state_map[thisEv->curr_state()] << ", " << thisEv->curr_floor() << endl;
    }
}




void ElevatorContext::Action(ElevatorButtonAction act) {
    assert(istate_);

    IStateFunc_Action func = actions_map_[act];
    ElevatorState next_state = (istate_->*func)();
    if (next_state != istate_->curr_state()) {
        istate_ = istates_map_[next_state];
    }
}
#pragma once

#include "IState.h"
#include "stdafx.h"


class ElevatorContext
{
public:
    explicit ElevatorContext(int min_floor, int max_floor);
    explicit ElevatorContext();
    ~ElevatorContext();

public:
    void Action(ElevatorButtonAction act);
    ElevatorState curr_state() const { return istate_->curr_state(); }

    int curr_floor()const { return curr_floor_; }

private:
    int curr_floor_;

    int running_milliseconds_per_floor_ {2000};  //默认2s跑一层/开门/关门
    int opening_closeing_milliseconds_ {3000};  //默认3s 开门/关门

public:
    const int kMaxFloor;
    const int kMinFloor;
private:
    IState *istate_{nullptr};

    //TODO: Use std::function<> to replace the function pointer?
    typedef ElevatorState(IState::* IStateFunc_Action)();   //执行成员函数的函数指针, 用于动态绑定调用不同对象的函数
    std::map<ElevatorButtonAction, IStateFunc_Action> actions_map_;

    std::map<ElevatorState, IState*> istates_map_;
};


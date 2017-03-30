#pragma once

#include "IState.h"
#include "stdafx.h"


class ElevatorContext
{
public:
    ElevatorContext();
    ~ElevatorContext();

public:
    void Action(ElevatorButtonAction act);
    ElevatorState curr_state() const { return istate_->curr_state(); }

private:
    IState *istate_{nullptr};

    //TODO: Use std::function<> to replace the function pointer?
    typedef ElevatorState(IState::* IStateFunc_Action)();   //执行成员函数的函数指针, 用于动态绑定调用不同对象的函数
    std::map<ElevatorButtonAction, IStateFunc_Action> actions_;

};


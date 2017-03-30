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
    typedef ElevatorState(IState::* IStateFunc_Action)();   //ִ�г�Ա�����ĺ���ָ��, ���ڶ�̬�󶨵��ò�ͬ����ĺ���
    std::map<ElevatorButtonAction, IStateFunc_Action> actions_;

};


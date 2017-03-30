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

    int running_milliseconds_per_floor_ {2000};  //Ĭ��2s��һ��/����/����
    int opening_closeing_milliseconds_ {3000};  //Ĭ��3s ����/����

public:
    const int kMaxFloor;
    const int kMinFloor;
private:
    IState *istate_{nullptr};

    //TODO: Use std::function<> to replace the function pointer?
    typedef ElevatorState(IState::* IStateFunc_Action)();   //ִ�г�Ա�����ĺ���ָ��, ���ڶ�̬�󶨵��ò�ͬ����ĺ���
    std::map<ElevatorButtonAction, IStateFunc_Action> actions_map_;

    std::map<ElevatorState, IState*> istates_map_;
};


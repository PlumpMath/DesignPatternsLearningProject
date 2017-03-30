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
    //����/ֹͣ Elevator Engine
    void PowerOn();
    void PowerOff();

    //Action������̰߳�ȫ�����ӿ�
    void PushAction(ElevatorButtonAction act);
    bool PopAction(ElevatorButtonAction& act);
    std::size_t ActionsQueueSize();
    void WaitAction();

    //ִ��ʵ�ʵĶ���
    void Action(ElevatorButtonAction act);

    //״̬��ȡ
    ElevatorState curr_state() const { return istate_->curr_state(); }
    int curr_floor()const { return curr_floor_; }

    bool engine_on()const { return engine_on_; }
private:
    std::atomic<bool> engine_on_ {false};
    std::thread* engine_ {nullptr};
    static void EngineProc(ElevatorContext*);

    //Action����Ķ���
    std::queue<ElevatorButtonAction> actions_queue_;
    std::mutex actions_queue_mutex_;
    std::condition_variable actions_cond_;
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


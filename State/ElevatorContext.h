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
    //启动/停止 Elevator Engine
    void PowerOn();
    void PowerOff();

    //Action缓存的线程安全操作接口
    void PushAction(ElevatorButtonAction act);
    bool PopAction(ElevatorButtonAction& act);
    std::size_t ActionsQueueSize();
    void WaitAction();

    //执行实际的动作
    void Action(ElevatorButtonAction act);

    //状态读取
    ElevatorState curr_state() const { return istate_->curr_state(); }
    int curr_floor()const { return curr_floor_; }

    bool engine_on()const { return engine_on_; }
private:
    std::atomic<bool> engine_on_ {false};
    std::thread* engine_ {nullptr};
    static void EngineProc(ElevatorContext*);

    //Action缓存的队列
    std::queue<ElevatorButtonAction> actions_queue_;
    std::mutex actions_queue_mutex_;
    std::condition_variable actions_cond_;
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


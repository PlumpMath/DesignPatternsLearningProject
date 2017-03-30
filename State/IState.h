#pragma once

//��������Щ״̬, �Ե�����ʾ��
enum class ElevatorState {
    kStop = 0,
    kStopOpening,
    kStopClosing,
    kRunning,
};

enum class ElevatorButtonAction {
    kClosePressed,
    kOpenPressed,
};


// ����״̬���ͳһ�ӿ�
class IState
{
public:

    virtual ElevatorState Open() = 0;
    virtual ElevatorState Close() = 0;

    virtual ElevatorState curr_state() const = 0;
};


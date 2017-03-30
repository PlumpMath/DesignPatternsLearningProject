// State.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ElevatorContext.h"
using namespace std;

int main()
{

    //for ACTION input
    const string kElevatorOpenString = "OPEN";
    const string kElevatorCloseString = "CLOSE";
    map<string, ElevatorButtonAction> ev_action_map;
    ev_action_map[kElevatorCloseString] = ElevatorButtonAction::kClosePressed;
    ev_action_map[kElevatorOpenString] = ElevatorButtonAction::kOpenPressed;

    //for STATE output
    map<ElevatorState, string> ev_state_map;
    ev_state_map[ElevatorState::kStop] = "STOP";
    ev_state_map[ElevatorState::kStopClosing] = "CLOSING";
    ev_state_map[ElevatorState::kStopOpening] = "OPENING";
    ev_state_map[ElevatorState::kRunning] = "RUNNING";

    cout << "Please press any Action [" << kElevatorOpenString << "|" << kElevatorCloseString << "] for Elevator..." << endl;

    ElevatorContext ev;
    while (true){
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);

        auto it = ev_action_map.find(s);
        if (it == ev_action_map.end()) {
            //ignore this input
        }
        else {
            ev.Action(it->second);
            cout << ev_state_map[ev.curr_state()] << endl;
        }
    }
        
    return 0;
}


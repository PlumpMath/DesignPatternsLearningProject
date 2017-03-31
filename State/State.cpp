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
    ev_state_map[ElevatorState::kStopClosed] = "CLOSED";
    ev_state_map[ElevatorState::kStopOpened] = "OPENED";
    ev_state_map[ElevatorState::kStopClosing] = "CLOSING";
    ev_state_map[ElevatorState::kStopOpening] = "OPENING";
    ev_state_map[ElevatorState::kRunning] = "RUNNING";


    ElevatorContext ev(-2, 20);
    cout << "Please press [" << kElevatorOpenString << "|" << kElevatorCloseString 
        << "] for this Elevator (Floor " << ev.kMinFloor << "," << ev.kMaxFloor << " ) ..." << endl;
    cout << "       press [QUIT|EXIT ] if want to quit" << endl;
    cout << "Init State: " << ev_state_map[ev.curr_state()] << ", Floor: " << ev.curr_floor() << endl;

    while (true) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (s == "QUIT" || s == "EXIT"){
            break;
        }

        auto it = ev_action_map.find(s);
        if (it == ev_action_map.end()) {
            //ignore this input
        }
        else {
            ev.Action(it->second);
            cout << ev_state_map[ev.curr_state()] << ", " << ev.curr_floor() << endl;
        }
    }
        
    return 0;
}


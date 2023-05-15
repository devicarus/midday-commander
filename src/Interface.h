//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_INTERFACE_H
#define MIDDAY_COMMANDER_INTERFACE_H

#include <map>

#include "FileView.h"
#include "State.h"
#include "action/Action.h"

class Action;

class Interface {
public:
    Action* promptAction();
    Interface& addHotkey(int key, Action* action);

    void initialize();
    void stop();
    void render(FileView& filesystem, State& state);
private:
    std::map<int, Action*> actions;
};


#endif //MIDDAY_COMMANDER_INTERFACE_H

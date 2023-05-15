//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_ACTION_H
#define MIDDAY_COMMANDER_ACTION_H

#include <vector>
#include <filesystem>

#include "../FileView.h"
#include "../Interface.h"
#include "../State.h"

class Interface;

class Action {
public:
    Action() = default;
    virtual void execute(FileView& filesystem, Interface& interface, State& state) = 0;
};

#endif //MIDDAY_COMMANDER_ACTION_H

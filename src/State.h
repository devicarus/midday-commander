//
// Created by Vojtěch Pašek on 13.05.2023.
//

#ifndef MIDDAY_COMMANDER_STATE_H
#define MIDDAY_COMMANDER_STATE_H

#include <set>

#include "entry/Entry.h"

class State {
public:
    bool running = true;
    std::set<Entry*> selected;
};


#endif //MIDDAY_COMMANDER_STATE_H

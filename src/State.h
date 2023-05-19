//
// Created by Vojtěch Pašek on 13.05.2023.
//

#ifndef MIDDAY_COMMANDER_STATE_H
#define MIDDAY_COMMANDER_STATE_H

#include <set>

#include "entry/Entry.h"
#include "Utility.h"

class State {
private:
    struct cmpEntry {
        bool operator() (const std::shared_ptr<Entry>& lhs, const std::shared_ptr<Entry>& rhs) const {
            return lhs->path < rhs->path;
        }
    };
public:
    bool running = true;
    std::set<std::shared_ptr<Entry>, cmpEntry> selected;
};


#endif //MIDDAY_COMMANDER_STATE_H

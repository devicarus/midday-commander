//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_ONCEACTION_H
#define MIDDAY_COMMANDER_ONCEACTION_H

#include "Action.h"

class OnceAction : public Action {
public:
    void execute(FileView& fileview, Interface& interface, State& state) override;
private:
    virtual void executeAction(FileView& fileview, State& state) = 0;
};

#endif //MIDDAY_COMMANDER_ONCEACTION_H

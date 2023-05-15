//
// Created by Vojtěch Pašek on 12.05.2023.
//

#ifndef MIDDAY_COMMANDER_INTERFACEACTION_H
#define MIDDAY_COMMANDER_INTERFACEACTION_H

#include "Action.h"

class InterfaceAction : public Action {
public:
    void execute(FileView& fileview, Interface& interface, State& state) override;
private:
    virtual void executeAction(Interface& interface, State& state) = 0;
};

#endif //MIDDAY_COMMANDER_INTERFACEACTION_H

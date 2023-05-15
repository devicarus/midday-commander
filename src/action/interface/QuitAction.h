//
// Created by Vojtěch Pašek on 12.05.2023.
//

#ifndef MIDDAY_COMMANDER_QUITACTION_H
#define MIDDAY_COMMANDER_QUITACTION_H

#include "../InterfaceAction.h"

class QuitAction : public InterfaceAction {
private:
    void executeAction(Interface& interface, State& state) override;
};

#endif //MIDDAY_COMMANDER_QUITACTION_H

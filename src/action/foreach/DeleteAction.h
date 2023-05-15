//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_DELETEACTION_H
#define MIDDAY_COMMANDER_DELETEACTION_H

#include "../ForEachAction.h"

class DeleteAction : public ForEachAction {
private:
    void executeAction(Entry* entry) override;
};


#endif //MIDDAY_COMMANDER_DELETEACTION_H

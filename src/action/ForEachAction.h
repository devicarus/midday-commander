//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FOREACHACTION_H
#define MIDDAY_COMMANDER_FOREACHACTION_H

#include "Action.h"

class ForEachAction : public Action {
public:
    void execute(FileView&, State&) override;
private:
    virtual void executeAction(FileView&, std::shared_ptr<Entry>) = 0;
};

#endif //MIDDAY_COMMANDER_FOREACHACTION_H

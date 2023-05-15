//
// Created by Vojtěch Pašek on 12.05.2023.
//

#ifndef MIDDAY_COMMANDER_CREATEACTION_H
#define MIDDAY_COMMANDER_CREATEACTION_H


#include "../OnceAction.h"

class CreateAction : public OnceAction {
private:
    void executeAction(FileView& fileview, State& state) override;
};


#endif //MIDDAY_COMMANDER_CREATEACTION_H

//
// Created by Vojtěch Pašek on 12.05.2023.
//

#ifndef MIDDAY_COMMANDER_CREATEFILEACTION_H
#define MIDDAY_COMMANDER_CREATEFILEACTION_H


#include "../OnceAction.h"

class CreateFileAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_CREATEFILEACTION_H

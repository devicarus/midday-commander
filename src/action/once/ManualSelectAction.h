//
// Created by Vojtěch Pašek on 20.05.2023.
//

#ifndef MIDDAY_COMMANDER_MANUALSELECTACTION_H
#define MIDDAY_COMMANDER_MANUALSELECTACTION_H

#include "../OnceAction.h"

class ManualSelectAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};

#endif //MIDDAY_COMMANDER_MANUALSELECTACTION_H

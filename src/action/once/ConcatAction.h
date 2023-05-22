//
// Created by Vojtěch Pašek on 22.05.2023.
//

#ifndef MIDDAY_COMMANDER_CONCATACTION_H
#define MIDDAY_COMMANDER_CONCATACTION_H

#include "../OnceAction.h"

class ConcatAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};

#endif //MIDDAY_COMMANDER_CONCATACTION_H

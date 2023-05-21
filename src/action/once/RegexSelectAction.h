//
// Created by Vojtěch Pašek on 21.05.2023.
//

#ifndef MIDDAY_COMMANDER_REGEXSELECTACTION_H
#define MIDDAY_COMMANDER_REGEXSELECTACTION_H

#include "../OnceAction.h"

class RegexSelectAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};

#endif //MIDDAY_COMMANDER_REGEXSELECTACTION_H

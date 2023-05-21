//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_DELETEACTION_H
#define MIDDAY_COMMANDER_DELETEACTION_H

#include "../ForEachAction.h"

class DeleteAction : public ForEachAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, std::shared_ptr<Entry>) override;
};

#endif //MIDDAY_COMMANDER_DELETEACTION_H

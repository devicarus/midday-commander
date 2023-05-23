//
// Created by Vojtěch Pašek on 21.05.2023.
//

#ifndef MIDDAY_COMMANDER_MOVEACTION_H
#define MIDDAY_COMMANDER_MOVEACTION_H

#include "../ForEachAction.h"

/**
 * @brief An Action that moves all \link Entry Entries \endlink in State.selected to FileView.wd
 */
class MoveAction : public ForEachAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, std::shared_ptr<Entry>) override;
};

#endif //MIDDAY_COMMANDER_MOVEACTION_H

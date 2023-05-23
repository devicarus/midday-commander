//
// Created by Vojtěch Pašek on 20.05.2023.
//

#ifndef MIDDAY_COMMANDER_COPYACTION_H
#define MIDDAY_COMMANDER_COPYACTION_H

#include "../ForEachAction.h"

/**
 * @brief An Action that copies all \link Entry Entries \endlink in State.selected to FileView.wd
 */
class CopyAction : public ForEachAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, std::shared_ptr<Entry>) override;
};

#endif //MIDDAY_COMMANDER_COPYACTION_H

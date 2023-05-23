//
// Created by Vojtěch Pašek on 21.05.2023.
//

#ifndef MIDDAY_COMMANDER_UNSELECTALLACTION_H
#define MIDDAY_COMMANDER_UNSELECTALLACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that clears State.selected
 */
class UnselectAllAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};

#endif //MIDDAY_COMMANDER_UNSELECTALLACTION_H

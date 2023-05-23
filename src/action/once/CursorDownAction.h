//
// Created by Vojtěch Pašek on 19.05.2023.
//

#ifndef MIDDAY_COMMANDER_CURSORDOWNACTION_H
#define MIDDAY_COMMANDER_CURSORDOWNACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that moves FileView.cursor one Entry down
 */
class CursorDownAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_CURSORDOWNACTION_H

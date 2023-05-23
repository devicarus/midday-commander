//
// Created by Vojtěch Pašek on 12.05.2023.
//

#ifndef MIDDAY_COMMANDER_CREATEFILEACTION_H
#define MIDDAY_COMMANDER_CREATEFILEACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that creates a blank file (user is asked for filename)
 */
class CreateFileAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_CREATEFILEACTION_H

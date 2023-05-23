//
// Created by Vojtěch Pašek on 21.05.2023.
//

#ifndef MIDDAY_COMMANDER_CREATESYMLINKACTION_H
#define MIDDAY_COMMANDER_CREATESYMLINKACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that creates a symlink to the currently Entry under FileView.cursor (user is asked for filename)
 */
class CreateSymlinkAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_CREATESYMLINKACTION_H

//
// Created by Vojtěch Pašek on 19.05.2023.
//

#ifndef MIDDAY_COMMANDER_OPENACTION_H
#define MIDDAY_COMMANDER_OPENACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that sets FileView.wd to the Folder under FileView.cursor (if it is Folder)
 */
class OpenAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_OPENACTION_H

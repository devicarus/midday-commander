//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_ONCEACTION_H
#define MIDDAY_COMMANDER_ONCEACTION_H

#include "Action.h"

/**
 * @brief A base class for \link Action Actions \endlink that are supposed to fire once
 */
class OnceAction : public Action {
public:
    void execute(FileView&, State&) override;
private:
    virtual void executeAction(FileView&, State&) = 0;
};

#endif //MIDDAY_COMMANDER_ONCEACTION_H

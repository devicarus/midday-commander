//
// Created by Vojtěch Pašek on 22.05.2023.
//

#ifndef MIDDAY_COMMANDER_CONCATACTION_H
#define MIDDAY_COMMANDER_CONCATACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that concatenates all \link File Files \endlink in State.selected into to a new one (user is asked for filename)
 */
class ConcatAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};

#endif //MIDDAY_COMMANDER_CONCATACTION_H

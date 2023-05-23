//
// Created by Vojtěch Pašek on 21.05.2023.
//

#ifndef MIDDAY_COMMANDER_REGEXSELECTACTION_H
#define MIDDAY_COMMANDER_REGEXSELECTACTION_H

#include "../OnceAction.h"

/**
 * @brief An Action that adds \link Entry Entries \endlink into State.selected if their filenames matches `RegEx` provided by user via a dialog
 */
class RegexSelectAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};

#endif //MIDDAY_COMMANDER_REGEXSELECTACTION_H

//
// Created by Vojtěch Pašek on 19.05.2023.
//

#ifndef MIDDAY_COMMANDER_GOBACKACTION_H
#define MIDDAY_COMMANDER_GOBACKACTION_H

#include "../OnceAction.h"

class GoBackAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_GOBACKACTION_H

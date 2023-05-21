//
// Created by Vojtěch Pašek on 19.05.2023.
//

#ifndef MIDDAY_COMMANDER_CURSORUPACTION_H
#define MIDDAY_COMMANDER_CURSORUPACTION_H

#include "../OnceAction.h"

class CursorUpAction : public OnceAction {
public:
    [[nodiscard]] std::unique_ptr<Action> clone() const override;
private:
    void executeAction(FileView&, State&) override;
};


#endif //MIDDAY_COMMANDER_CURSORUPACTION_H

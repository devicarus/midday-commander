//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_ACTION_H
#define MIDDAY_COMMANDER_ACTION_H

#include <vector>
#include <filesystem>

#include "../FileView.h"
#include "../State.h"

class Action {
public:
    Action() = default;
    virtual ~Action() = default;
    virtual void execute(FileView&, State&) = 0;
    [[nodiscard]] virtual std::unique_ptr<Action> clone() const = 0;
};

#endif //MIDDAY_COMMANDER_ACTION_H

//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_INTERFACE_H
#define MIDDAY_COMMANDER_INTERFACE_H

#include <map>
#include "ncurses.h"

#include "../FileView.h"
#include "../State.h"
#include "../action/Action.h"

#define KEY_RETURN '\n'// ncurses provides only KEY_ENTER, which is the numpad one


class Interface {
public:
    [[nodiscard]] const std::shared_ptr<Action>& promptAction() const;
    Interface& addHotkey(int key, const Action& action);

    void initialize() const;
    void render(FileView&, State&);
    void stop();
private:
    std::map<int, std::shared_ptr<Action>> actions;
};


#endif //MIDDAY_COMMANDER_INTERFACE_H

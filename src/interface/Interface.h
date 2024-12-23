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
#include "Theme.h"
#include "Color.h"

#define KEY_RETURN '\n'// ncurses provides only KEY_ENTER, which is the numpad one

/**
 * @brief Represents the main interface of the Application
 */
class Interface {
public:
    [[nodiscard]] const std::shared_ptr<Action>& promptAction() const;
    Interface& addHotkey(int key, const Action& action);
    Interface& setTheme(Theme);

    /**
     * @brief Initializes `ncurses` and prepares
     */
    void initialize() const;

    /**
     * @brief Shows the file view
     */
    void render(FileView&, State&);

    /**
     * @brief Stops `ncurses`
     */
    void stop();
private:
    std::map<int, std::shared_ptr<Action>> actions;
    Theme theme;

    void generateColorPairs() const;
};


#endif //MIDDAY_COMMANDER_INTERFACE_H

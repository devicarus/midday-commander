//
// Created by Vojtěch Pašek on 20.05.2023.
//

#ifndef MIDDAY_COMMANDER_THEME_H
#define MIDDAY_COMMANDER_THEME_H

#include "ncurses.h"

#define COLOR_DEFAULT (-1)

/**
 * @brief Represents a set of colors used by Interface
 */
class Theme {
public:
    /**
     * @brief Constructs a Theme using default colors of the terminal
     * @warning Only for testing purposes, corsor and selection probably won't be visible
     */
    Theme();

    /**
     * @brief Constructs a Theme using provided colors
     * @note All colors are represented as ANSI color codes
     * @param primary Background of cursored-on Entry
     * @param secondary Background of selected \link Entry Entries \endlink
     * @param background Default background
     * @param accent1 File foreground
     * @param accent2 Folder foreground
     * @param accent3 Symlink foreground
     */
    Theme(NCURSES_COLOR_T primary,
          NCURSES_COLOR_T secondary,
          NCURSES_COLOR_T background,
          NCURSES_COLOR_T accent1,
          NCURSES_COLOR_T accent2,
          NCURSES_COLOR_T accent3);

    /**
     * @brief Background of cursored-on Entry
     */
    NCURSES_COLOR_T primary;
    /**
     * @brief Background of selected \link Entry Entries \endlink
     */
    NCURSES_COLOR_T secondary;
    /**
     * @brief Default background
     */
    NCURSES_COLOR_T background;
    /**
     * @brief File foreground
     */
    NCURSES_COLOR_T accent1;
    /**
     * @brief Folder foreground
     */
    NCURSES_COLOR_T accent2;
    /**
     * @brief Symlink foreground
     */
    NCURSES_COLOR_T accent3;

    static Theme defaultTheme;
};


#endif //MIDDAY_COMMANDER_THEME_H

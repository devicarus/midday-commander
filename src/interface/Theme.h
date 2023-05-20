//
// Created by Vojtěch Pašek on 20.05.2023.
//

#ifndef MIDDAY_COMMANDER_THEME_H
#define MIDDAY_COMMANDER_THEME_H

#include "ncurses.h"

#define COLOR_DEFAULT (-1)

class Theme {
public:
    Theme();
    Theme(NCURSES_COLOR_T primary,
          NCURSES_COLOR_T secondary,
          NCURSES_COLOR_T background,
          NCURSES_COLOR_T accent1,
          NCURSES_COLOR_T accent2,
          NCURSES_COLOR_T accent3);

    NCURSES_COLOR_T primary;
    NCURSES_COLOR_T secondary;
    NCURSES_COLOR_T background;
    NCURSES_COLOR_T accent1;
    NCURSES_COLOR_T accent2;
    NCURSES_COLOR_T accent3;
};


#endif //MIDDAY_COMMANDER_THEME_H

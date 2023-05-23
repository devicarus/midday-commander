//
// Created by Vojtěch Pašek on 20.05.2023.
//
#include "Theme.h"

Theme::Theme(NCURSES_COLOR_T primary,
             NCURSES_COLOR_T secondary,
             NCURSES_COLOR_T background,
             NCURSES_COLOR_T accent1,
             NCURSES_COLOR_T accent2,
             NCURSES_COLOR_T accent3)
: primary(primary), secondary(secondary), background(background), accent1(accent1), accent2(accent2), accent3(accent3) {}

Theme::Theme()
: primary(COLOR_DEFAULT), secondary(COLOR_DEFAULT), background(COLOR_DEFAULT), accent1(COLOR_DEFAULT), accent2(COLOR_DEFAULT), accent3(COLOR_DEFAULT) {}

Theme Theme::defaultTheme = Theme{240, 235, -1, 7, 3, 5};


//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "Color.h"

#include "ncurses.h"

void Color::set(ColorPair colorPair) {
    attron(COLOR_PAIR(static_cast<int>(colorPair)));
}

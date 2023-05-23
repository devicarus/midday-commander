//
// Created by Vojtěch Pašek on 20.05.2023.
//

#ifndef MIDDAY_COMMANDER_COLOR_H
#define MIDDAY_COMMANDER_COLOR_H

enum class ColorPair {
    DEFAULT_BACKGROUND = 10,
    DEFAULT_PRIMARY = 11,
    DEFAULT_SECONDARY = 12,
    ACCENT1_BACKGROUND = 1,
    ACCENT2_BACKGROUND = 2,
    ACCENT3_BACKGROUND = 3,
    ACCENT1_PRIMARY = 4,
    ACCENT2_PRIMARY = 5,
    ACCENT3_PRIMARY = 6,
    ACCENT1_SECONDARY = 7,
    ACCENT2_SECONDARY = 8,
    ACCENT3_SECONDARY = 9,
};

/**
 * @brief A utility class for work with terminal colors
 */
class Color {
public:
    static void set(ColorPair);
};

#endif //MIDDAY_COMMANDER_COLOR_H

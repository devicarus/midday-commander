//
// Created by Vojtěch Pašek on 21.05.2023.
//

#ifndef MIDDAY_COMMANDER_MODAL_H
#define MIDDAY_COMMANDER_MODAL_H

#include "string"
#include "ncurses.h"

/**
 * @brief A helper class allowing \link Action Actions \endlink to receive input and show messages
 */
class Modal {
public:
    Modal(std::string  title, int height, int width);
    Modal(int height, int width);
    Modal& show();
    [[nodiscard]] std::string input();
    Modal& message(std::string);
    void destroy();
private:
    std::string title;
    int height;
    int width;
    WINDOW* window{};
};


#endif //MIDDAY_COMMANDER_MODAL_H

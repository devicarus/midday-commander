//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "Modal.h"

#include <utility>

#include "ncurses.h"

#define KEY_BACKSPACE_ALT 127

Modal::Modal(std::string title, int height, int width)
: title(std::move(title)), height(height), width(width), window(nullptr) {}

Modal::Modal(int height, int width)
: height(height), width(width), window(nullptr) {}

Modal& Modal::show() {
    window = newwin(height, width, (LINES - height)/2, (COLS - width)/2);
    box(window, 0, 0);
    mvwprintw(window, 0, 0, title.data());
    return (*this);
}

void Modal::destroy() {
    delwin(window);
}

std::string Modal::input() {
    wmove(window, 1, 1);
    curs_set(1);

    std::string input;
    int ch;
    while ((ch = wgetch(window)) != '\n' ) {
        if (ch == KEY_BACKSPACE || ch == KEY_BACKSPACE_ALT) {
            if (input.empty()) continue;
            input.pop_back();

            // deletes the character form the modal (breaks the window border)
            mvwdelch(window, getcury(window), getcurx(window)-1);

            // restore the window border
            mvwdelch(window, 1, getmaxx(window)-2);
            box(window, 0, 0);
            mvwprintw(window, 0, 0, title.data());

            // place the cursor back
            wmove(window, 1, (int)input.size()+1);
        } else if (input.size() + 2 < (long unsigned int)width) {
            input.push_back(static_cast<char>(ch));
            waddch(window, ch);
        }
    }

    curs_set(0);

    return input;
}

Modal &Modal::message(std::string message) {
    mvwprintw(window, 1, 1, message.data());
    wgetch(window); // wait for confirmation
    return (*this);
}

//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ncurses.h"

#include "Interface.h"

Interface &Interface::addHotkey(int key, Action *action) {
    actions.insert({key, action});
    return (*this);
}

Action* Interface::promptAction() {
    while(true) {
        auto it = actions.find(getch());
        if (it != actions.end())
            return it->second;
    }
}

void Interface::initialize() {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    scrollok(stdscr, TRUE);
    start_color();
    use_default_colors();

    // make configurable (setColors/setTheme?)
    init_pair(1, -1, -1);
    init_pair(2, COLOR_YELLOW, -1);
}

void Interface::stop() {
    endwin();
}

void Interface::render(FileView& filesystem, State& state) {
    clear();
    for(auto entry : filesystem.getCurrent()) {
        entry->print();
        state.selected.insert(entry);
        printw("\n");
    }
}

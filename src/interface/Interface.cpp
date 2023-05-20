//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "Interface.h"

#include "ncurses.h"

Interface &Interface::addHotkey(int key, const Action& action) {
    actions.emplace(key, action.clone());
    return (*this);
}

const std::shared_ptr<Action>& Interface::promptAction() const {
    while(true) {
        auto it = actions.find(getch());
        if (it != actions.end())
            return it->second;
    }
}

void Interface::initialize() const {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    start_color();
    use_default_colors();
    curs_set(0);
}

void Interface::stop() {
    endwin();
}

void Interface::render(FileView& fileView, State& state) {
    clear();
    auto entries = fileView.getCurrent();
    for (std::size_t i = fileView.scroll_cursor; i < std::min(fileView.scroll_cursor + LINES, entries.size()); ++i) {
        auto entry = entries[i];
        if(fileView.cursor == i)
            entry->print(Modifier::CURSOR);
        else if (state.selected.find(entry) != state.selected.end())
            entry->print(Modifier::SELECTED);
        else
            entry->print(Modifier::NONE);
        printw("\n");
    }
}

//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "Interface.h"

#include "ncurses.h"

#include "Color.h"

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
    generateColorPairs();
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

Interface &Interface::setTheme(Theme newTheme) {
    theme = newTheme;
    return (*this);
}

void Interface::generateColorPairs() const {
    init_pair(static_cast<int>(ColorPair::DEFAULT_BACKGROUND), COLOR_DEFAULT, theme.background);
    init_pair(static_cast<int>(ColorPair::DEFAULT_PRIMARY), COLOR_DEFAULT, theme.primary);
    init_pair(static_cast<int>(ColorPair::DEFAULT_SECONDARY), COLOR_DEFAULT, theme.secondary);

    init_pair(static_cast<int>(ColorPair::ACCENT1_BACKGROUND), theme.accent1, theme.background);
    init_pair(static_cast<int>(ColorPair::ACCENT2_BACKGROUND), theme.accent2, theme.background);
    init_pair(static_cast<int>(ColorPair::ACCENT3_BACKGROUND), theme.accent3, theme.background);

    init_pair(static_cast<int>(ColorPair::ACCENT1_PRIMARY), theme.accent1, theme.primary);
    init_pair(static_cast<int>(ColorPair::ACCENT2_PRIMARY), theme.accent2, theme.primary);
    init_pair(static_cast<int>(ColorPair::ACCENT3_PRIMARY), theme.accent3, theme.primary);

    init_pair(static_cast<int>(ColorPair::ACCENT1_SECONDARY), theme.accent1, theme.secondary);
    init_pair(static_cast<int>(ColorPair::ACCENT2_SECONDARY), theme.accent2, theme.secondary);
    init_pair(static_cast<int>(ColorPair::ACCENT3_SECONDARY), theme.accent3, theme.secondary);
}
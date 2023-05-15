//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ncurses.h"

#include "Folder.h"

Folder::Folder(std::filesystem::path path)
: Entry(std::move(path)) {}

void Folder::print() const {
    attron(COLOR_PAIR(2));
    printw(("folder: " + path.filename().string()).c_str());
    attron(COLOR_PAIR(1));
}

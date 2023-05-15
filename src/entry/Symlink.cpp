//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ncurses.h"

#include "Symlink.h"

Symlink::Symlink(std::filesystem::path path)
: Entry(std::move(path)) {}

void Symlink::print() const {
    printw(("symlink: " + path.filename().string()).c_str());
}

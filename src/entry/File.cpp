//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ncurses.h"

#include "File.h"

File::File(std::filesystem::path path)
: Entry(std::move(path)) {}

void File::print() const {
    printw(("file: " + path.filename().string()).c_str());
}

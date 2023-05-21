//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "File.h"

#include "ncurses.h"

#include "../interface/Color.h"
#include "../Utility.h"

File::File(std::filesystem::path path)
: Entry(std::move(path)) {}

void File::print(Modifier modifier) const {
    auto filename = Utility::escape(path.filename());

    Color::set([modifier]()->ColorPair{
        switch (modifier) {
            case Modifier::CURSOR: return ColorPair::ACCENT1_PRIMARY;
            case Modifier::SELECTED: return ColorPair::ACCENT1_SECONDARY;
            case Modifier::NONE: default: return ColorPair::ACCENT1_BACKGROUND;
        }
    }());
    printw(filename.c_str());

    for (int i = (int)filename.size(); i < COLS-1; ++i)
        printw(" ");
}

bool File::remove() {
    std::filesystem::remove(path);
    return true;
}

bool File::copy(std::filesystem::path target) {
    if (std::filesystem::exists(target) && std::filesystem::equivalent(path, target)) return false;
    std::filesystem::copy_file(path, target, std::filesystem::copy_options::overwrite_existing);
    return true;
}

bool File::move(std::filesystem::path target) {
    if (!copy(target)) return false;
    return remove();
}

bool File::isFile() {
    return true;
}

bool File::isFolder() {
    return false;
}

bool File::isSymlink() {
    return false;
}

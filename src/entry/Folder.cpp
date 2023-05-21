//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "Folder.h"

#include "ncurses.h"

#include "../Utility.h"
#include "../interface/Color.h"

Folder::Folder(std::filesystem::path path)
: Entry(std::move(path)) {}

void Folder::print(Modifier modifier) const {
    auto filename = Utility::escape(path.filename());

    Color::set([modifier]()->ColorPair{
        switch (modifier) {
            case Modifier::CURSOR: return ColorPair::ACCENT2_PRIMARY;
            case Modifier::SELECTED: return ColorPair::ACCENT2_SECONDARY;
            case Modifier::NONE: default: return ColorPair::ACCENT2_BACKGROUND;
        }
    }());
    printw(filename.c_str());

    Color::set([modifier]()->ColorPair{
        switch (modifier) {
            case Modifier::CURSOR: return ColorPair::DEFAULT_PRIMARY;
            case Modifier::SELECTED: return ColorPair::DEFAULT_SECONDARY;
            case Modifier::NONE: default: return ColorPair::DEFAULT_BACKGROUND;
        }
    }());
    printw("/");

    for (int i = (int)filename.size(); i < COLS-2; ++i)
        printw(" ");
}

bool Folder::remove() {
    std::filesystem::remove_all(path);
    return true;
}

bool Folder::copy(std::filesystem::path target) {
    std::string relative = std::filesystem::relative(target, path);
    if (relative.size() == 1 || (relative[0] != '.' && relative[1] != '.')) return false;
    std::filesystem::copy(path, target,
                          std::filesystem::copy_options::recursive
                          | std::filesystem::copy_options::overwrite_existing);
    return true;
}

bool Folder::move(std::filesystem::path target) {
    if (!copy(target)) return false;
    return remove();
}

bool Folder::isFile() {
    return false;
}

bool Folder::isFolder() {
    return true;
}

bool Folder::isSymlink() {
    return false;
}

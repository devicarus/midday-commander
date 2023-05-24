//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "Symlink.h"

#include "ncurses.h"
#include <set>

#include "../interface/Color.h"
#include "../Utility.h"

Symlink::Symlink(const std::filesystem::path& path)
: Entry(path) {
    std::set<std::filesystem::path> history;

    auto current = path;
    while (is_symlink(current)) {
        auto next = std::filesystem::read_symlink(current);
        if (next.is_relative())
            next = current.parent_path()/next;

        current = next;

        if (!history.insert(current.filename()).second) {
            circular = true;
            break;
        }
    }
}

void Symlink::print(Modifier modifier) const {
    auto filename = Utility::escape(path.filename());

    Color::set([modifier]()->ColorPair{
        switch (modifier) {
            case Modifier::CURSOR: return ColorPair::ACCENT3_PRIMARY;
            case Modifier::SELECTED: return ColorPair::ACCENT3_SECONDARY;
            case Modifier::NONE: default: return ColorPair::ACCENT3_BACKGROUND;
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
    printw("@");
    for (int i = (int)filename.size(); i < COLS-2; ++i)
        printw(" ");
}

bool Symlink::remove() {
    std::filesystem::remove(path);
    return true;
}

bool Symlink::copy(std::filesystem::path target) {
    if (std::filesystem::exists(target) && std::filesystem::equivalent(path, target)) return false;
    std::filesystem::copy_symlink(path, target);
    return true;
}

bool Symlink::move(std::filesystem::path target) {
    if (!copy(target)) return false;
    return remove();
}

bool Symlink::isFile() {
    return false;
}

bool Symlink::isFolder() {
    return !circular && std::filesystem::is_directory(path);
}

bool Symlink::isSymlink() {
    return true;
}

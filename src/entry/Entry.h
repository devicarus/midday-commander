//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_ENTRY_H
#define MIDDAY_COMMANDER_ENTRY_H

#include <filesystem>

class Entry {
public:
    explicit Entry(std::filesystem::path path);
    virtual void print() const = 0;
    std::filesystem::path path;
};

#endif //MIDDAY_COMMANDER_ENTRY_H

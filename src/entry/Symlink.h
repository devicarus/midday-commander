//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_SYMLINK_H
#define MIDDAY_COMMANDER_SYMLINK_H

#include <filesystem>

#include "Entry.h"

class Symlink : public Entry {
public:
    explicit Symlink(std::filesystem::path path);
    void print() const override;
};


#endif //MIDDAY_COMMANDER_SYMLINK_H

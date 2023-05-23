//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_SYMLINK_H
#define MIDDAY_COMMANDER_SYMLINK_H

#include <filesystem>

#include "Entry.h"

/**
 * @brief Represents a symlink in the program
 */
class Symlink : public Entry {
public:
    explicit Symlink(std::filesystem::path);
    void print(Modifier) const override;

    bool isFile() override;
    bool isFolder() override;
    bool isSymlink() override;

    bool remove() override;
    bool move(std::filesystem::path target) override;
    bool copy(std::filesystem::path target) override;
};


#endif //MIDDAY_COMMANDER_SYMLINK_H

//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_ENTRY_H
#define MIDDAY_COMMANDER_ENTRY_H

#include <filesystem>

#include "Modifier.h"

/**
 * @brief An abstract class representing a general FileView entry
 */
class Entry {
public:
    std::filesystem::path path;

    explicit Entry(std::filesystem::path path);
    virtual ~Entry() = default;

    virtual void print(Modifier modifier) const = 0;

    virtual bool isFile() = 0;
    virtual bool isFolder() = 0;
    virtual bool isSymlink() = 0;

    virtual bool remove() = 0;
    virtual bool copy(std::filesystem::path target) = 0;
    virtual bool move(std::filesystem::path target) = 0;
};

#endif //MIDDAY_COMMANDER_ENTRY_H

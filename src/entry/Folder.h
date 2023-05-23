//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FOLDER_H
#define MIDDAY_COMMANDER_FOLDER_H

#include <filesystem>

#include "Entry.h"

/**
 * @brief Represents a folder in the program
 */
class Folder : public Entry {
public:
    explicit Folder(std::filesystem::path);
    void print(Modifier) const override;

    bool isFile() override;
    bool isFolder() override;
    bool isSymlink() override;

    bool remove() override;
    bool move(std::filesystem::path target) override;
    bool copy(std::filesystem::path target) override;
};


#endif //MIDDAY_COMMANDER_FOLDER_H

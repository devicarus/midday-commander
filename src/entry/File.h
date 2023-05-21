//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FILE_H
#define MIDDAY_COMMANDER_FILE_H

#include <filesystem>

#include "Entry.h"

class File : public Entry {
public:
    explicit File(std::filesystem::path);
    void print(Modifier) const override;

    bool isFile() override;
    bool isFolder() override;
    bool isSymlink() override;

    bool remove() override;
    bool copy(std::filesystem::path target) override;
    bool move(std::filesystem::path target) override;
};


#endif //MIDDAY_COMMANDER_FILE_H

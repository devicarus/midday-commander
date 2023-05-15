//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FOLDER_H
#define MIDDAY_COMMANDER_FOLDER_H

#include <filesystem>

#include "Entry.h"

class Folder : public Entry {
public:
    explicit Folder(std::filesystem::path path);
    void print() const override;
};


#endif //MIDDAY_COMMANDER_FOLDER_H

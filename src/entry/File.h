//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FILE_H
#define MIDDAY_COMMANDER_FILE_H

#include <filesystem>

#include "Entry.h"

class File : public Entry {
public:
    explicit File(std::filesystem::path path);
    void print() const override;
};


#endif //MIDDAY_COMMANDER_FILE_H

//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FILEVIEW_H
#define MIDDAY_COMMANDER_FILEVIEW_H

#include <vector>
#include <filesystem>

#include "entry/Entry.h"

class FileView {
public:
    FileView();
    explicit FileView(std::filesystem::path wd);
    std::filesystem::path wd;
    Entry* cursor; // maybe index instead?

    [[nodiscard]] std::vector<Entry*> getCurrent() const;
};


#endif //MIDDAY_COMMANDER_FILEVIEW_H

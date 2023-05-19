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
    size_t cursor = 0;
    size_t scroll_cursor = 0;

    [[nodiscard]] std::vector<std::shared_ptr<Entry>> getCurrent(bool recursive = false);
    void cd(std::filesystem::path);
};


#endif //MIDDAY_COMMANDER_FILEVIEW_H

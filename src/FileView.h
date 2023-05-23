//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_FILEVIEW_H
#define MIDDAY_COMMANDER_FILEVIEW_H

#include <vector>
#include <filesystem>

#include "entry/Entry.h"

/**
 * @brief Represents a file view of the Application
 */
class FileView {
public:
    /**
     * @brief Constructs a FileView  with \p wd set as the current directory
     */
    FileView();

    /**
     * @brief Constructs a FileView  with \p wd set as the provided directory
     */
    explicit FileView(std::filesystem::path wd);

    /**
     * @brief Working directory
     */
    std::filesystem::path wd;

    size_t cursor = 0;
    size_t scroll_cursor = 0;

    /**
     * @brief Get \link Entry Entries \endlink representing all files/folders in \p wd
     */
    [[nodiscard]] std::vector<std::shared_ptr<Entry>> getCurrent(bool recursive = false);

    /**
     * @brief Change directory
     */
    void cd(std::filesystem::path);
};


#endif //MIDDAY_COMMANDER_FILEVIEW_H

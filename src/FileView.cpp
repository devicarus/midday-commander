//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "FileView.h"

#include "Utility.h"

FileView::FileView()
: wd(std::filesystem::current_path()) {}

FileView::FileView(std::filesystem::path wd)
: wd(std::move(wd)) {}

std::vector<std::shared_ptr<Entry>> FileView::getCurrent(bool recursive) {
    std::vector<std::shared_ptr<Entry>> entries;

    // emergency fallback, shouldn't be able to happen
    if (!exists(wd)) wd = std::filesystem::current_path();

    if (recursive)
        for (const auto &it: std::filesystem::recursive_directory_iterator{wd})
            entries.push_back(Utility::makeEntry(it));
    else
        for (const auto &it: std::filesystem::directory_iterator{wd})
            entries.push_back(Utility::makeEntry(it));

    return entries;
}

void FileView::cd(std::filesystem::path path) {
    wd = std::move(path);
    cursor = 0;
    scroll_cursor = 0;
}

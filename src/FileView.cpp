//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "FileView.h"

#include <utility>
#include "entry/Folder.h"
#include "entry/File.h"
#include "entry/Symlink.h"

FileView::FileView()
: wd(std::filesystem::current_path()) {}

FileView::FileView(std::filesystem::path wd)
: wd(std::move(wd)) {}

std::vector<Entry*> FileView::getCurrent() const {
    std::vector<Entry*> entries;
    for (const auto& it : std::filesystem::directory_iterator{wd}) {
        if (is_directory(it))
            entries.push_back(new Folder{it});
        else if (is_regular_file(it))
            entries.push_back(new File{it});
        else if (is_symlink(it))
            entries.push_back(new Symlink{it});
    }
    return entries;
}

void FileView::cd(std::filesystem::path path) {
    wd = std::move(path);
    cursor = 0;
    scroll_cursor = 0;
}

//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "CreateSymlinkAction.h"

#include "../../interface/Modal.h"

void CreateSymlinkAction::executeAction(FileView &fileView, State &state) {
    Modal modal("Create symlink", 3, 30);
    modal.show();
    auto target_symlink = fileView.wd/modal.input();
    modal.destroy();

    if (exists(target_symlink))
        Modal(3,18).show().message(" Already exists ").destroy();
    else {
        auto target_dest = fileView.getCurrent().at(fileView.cursor);
        if (target_dest->isFile())
            std::filesystem::create_symlink(target_dest->path, target_symlink);
        else
            std::filesystem::create_directory_symlink(target_dest->path, target_symlink);
    }
}

std::unique_ptr<Action> CreateSymlinkAction::clone() const {
    return std::make_unique<CreateSymlinkAction>(*this);
}
//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "CreateFolderAction.h"

#include "../../interface/Modal.h"

void CreateFolderAction::executeAction(FileView &fileView, State &state) {
    Modal modal("Create folder", 3, 30);
    modal.show();
    auto target = fileView.wd/modal.input();
    modal.destroy();

    if (exists(target))
        Modal(3,18).show().message(" Already exists ").destroy();
    else
        std::filesystem::create_directories(target);
}

std::unique_ptr<Action> CreateFolderAction::clone() const {
    return std::make_unique<CreateFolderAction>(*this);
}
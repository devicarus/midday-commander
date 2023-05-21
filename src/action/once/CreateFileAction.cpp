//
// Created by Vojtěch Pašek on 12.05.2023.
//

#include "CreateFileAction.h"

#include <fstream>

#include "../../interface/Modal.h"

void CreateFileAction::executeAction(FileView &fileView, State &state) {
    Modal modal("Create file", 3, 30);
    modal.show();
    auto target = fileView.wd/modal.input();
    modal.destroy();

    if (exists(target))
        Modal(3,18).show().message(" Already exists ").destroy();
    else {
        std::ofstream file (fileView.wd/modal.input());
        file.close();
    }
}

std::unique_ptr<Action> CreateFileAction::clone() const {
    return std::make_unique<CreateFileAction>(*this);
}

//
// Created by Vojtěch Pašek on 19.05.2023.
//

#include "OpenAction.h"
#include "../../interface/Modal.h"

void OpenAction::executeAction(FileView& fileView, State&) {
    auto target = fileView.getCurrent().at(fileView.cursor);
    if (target->isFolder())
        fileView.cd(target->path);
}

std::unique_ptr<Action> OpenAction::clone() const {
    return std::make_unique<OpenAction>(*this);
}

//
// Created by Vojtěch Pašek on 19.05.2023.
//

#include "GoBackAction.h"

void GoBackAction::executeAction(FileView& fileView, State&) {
    fileView.cd(fileView.wd.parent_path());
}

std::unique_ptr<Action> GoBackAction::clone() const {
    return std::make_unique<GoBackAction>(*this);
}

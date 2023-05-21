//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "MoveAction.h"

void MoveAction::executeAction(FileView& fileView, std::shared_ptr<Entry> entry) {
    entry->move(fileView.wd/entry->path.filename());
}

std::unique_ptr<Action> MoveAction::clone() const {
    return std::make_unique<MoveAction>(*this);
}

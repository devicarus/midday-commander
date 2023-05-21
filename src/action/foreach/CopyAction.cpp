//
// Created by Vojtěch Pašek on 20.05.2023.
//

#include "CopyAction.h"

void CopyAction::executeAction(FileView& fileView, std::shared_ptr<Entry> entry) {
    entry->copy(fileView.wd/entry->path.filename());
}

std::unique_ptr<Action> CopyAction::clone() const {
    return std::make_unique<CopyAction>(*this);
}

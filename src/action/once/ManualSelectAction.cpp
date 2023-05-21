//
// Created by Vojtěch Pašek on 20.05.2023.
//

#include "ManualSelectAction.h"

void ManualSelectAction::executeAction(FileView& fileView, State& state) {
    auto entry = fileView.getCurrent().at(fileView.cursor);
    if (!state.selected.insert(entry).second)
        state.selected.erase(entry);
}

std::unique_ptr<Action> ManualSelectAction::clone() const {
    return std::make_unique<ManualSelectAction>(*this);
}

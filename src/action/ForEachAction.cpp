//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ForEachAction.h"

void ForEachAction::execute(FileView& fileView, State& state) {
    for (const auto& entry : state.selected)
        executeAction(fileView, entry);
    state.selected.clear();
}

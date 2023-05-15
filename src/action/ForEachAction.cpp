//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ForEachAction.h"

void ForEachAction::execute(FileView& fileview, [[maybe_unused]] Interface& interface, State& state) {
    for (auto entry : state.selected)
        executeAction(entry);
}

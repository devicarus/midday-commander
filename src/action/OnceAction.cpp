//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "OnceAction.h"

// to unify interfaces with ForEach Actions
void OnceAction::execute(FileView& fileView, State& state) {
    executeAction(fileView, state);
}

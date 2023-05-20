//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "OnceAction.h"

void OnceAction::execute(FileView& fileView, State& state) {
    executeAction(fileView, state);
}

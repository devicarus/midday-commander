//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "OnceAction.h"

void OnceAction::execute(FileView& fileview, Interface& interface, State& state) {
    executeAction(fileview, state);
}

//
// Created by Vojtěch Pašek on 12.05.2023.
//

#include "InterfaceAction.h"

void InterfaceAction::execute(FileView& fileview, Interface& interface, State& state) {
    executeAction(interface, state);
}

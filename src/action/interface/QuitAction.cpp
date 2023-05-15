//
// Created by Vojtěch Pašek on 12.05.2023.
//

#include "QuitAction.h"

void QuitAction::executeAction(Interface& interface, State& state) {
    state.running = false;
    interface.stop();
}

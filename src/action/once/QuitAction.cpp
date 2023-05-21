//
// Created by Vojtěch Pašek on 12.05.2023.
//

#include "QuitAction.h"

void QuitAction::executeAction(FileView&, State& state) {
    state.running = false;
}

std::unique_ptr<Action> QuitAction::clone() const {
    return std::make_unique<QuitAction>(*this);
}

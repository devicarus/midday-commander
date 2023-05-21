//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "UnselectAllAction.h"

void UnselectAllAction::executeAction(FileView&, State& state) {
    state.selected.clear();
}

std::unique_ptr<Action> UnselectAllAction::clone() const {
    return std::make_unique<UnselectAllAction>(*this);
}

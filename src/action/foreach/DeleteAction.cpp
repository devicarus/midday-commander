//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ncurses.h"

#include "DeleteAction.h"

void DeleteAction::executeAction(FileView&, std::shared_ptr<Entry> entry) {
    entry->remove();
}

std::unique_ptr<Action> DeleteAction::clone() const {
    return std::make_unique<DeleteAction>(*this);
}

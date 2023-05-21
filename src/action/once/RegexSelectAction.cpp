//
// Created by Vojtěch Pašek on 21.05.2023.
//

#include "RegexSelectAction.h"

#include "regex"

#include "../../interface/Modal.h"

void RegexSelectAction::executeAction(FileView& fileView, State& state) {
    Modal modal("RegEx search", 3, 30);
    modal.show();

    std::regex pattern;
    try { // unfortunately std::regex lacks any validation besides this exception
        pattern = modal.input();
    } catch (const std::regex_error& ) { /* do nothing */ }

    modal.destroy();

    for (const auto& entry : fileView.getCurrent(true))
        if(std::regex_search(entry->path.filename().string(), pattern))
            state.selected.insert(entry);
}

std::unique_ptr<Action> RegexSelectAction::clone() const {
    return std::make_unique<RegexSelectAction>(*this);
}

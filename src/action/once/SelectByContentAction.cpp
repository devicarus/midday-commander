//
// Created by Vojtěch Pašek on 22.05.2023.
//

#include "SelectByContentAction.h"

#include "fstream"
#include "regex"

#include "../../interface/Modal.h"

void SelectByContentAction::executeAction(FileView& fileView, State& state) {
    Modal modal("Search by content", 3, 30);
    modal.show();

    std::regex pattern;
    try { // unfortunately std::regex lacks any validation besides this exception
        pattern = modal.input();
    } catch (const std::regex_error& ) { /* do nothing */ }

    modal.destroy();

    for (const auto& entry : fileView.getCurrent(true)) {
        if (!entry->isFile()) continue;

        std::ifstream file (entry->path);
        std::string str;

        file.seekg(0, std::ios::end);
        str.reserve(file.tellg());
        file.seekg(0, std::ios::beg);

        str.assign((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());

        if (regex_search(str,pattern))
            state.selected.insert(entry);

        file.close();
    }
}

std::unique_ptr<Action> SelectByContentAction::clone() const {
    return std::make_unique<SelectByContentAction>(*this);
}

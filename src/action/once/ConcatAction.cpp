//
// Created by Vojtěch Pašek on 22.05.2023.
//

#include "ConcatAction.h"

#include "fstream"

#include "../../interface/Modal.h"

void ConcatAction::executeAction(FileView& fileView, State& state) {
    Modal modal("New filename", 3, 30);
    modal.show();
    std::ofstream target (fileView.wd/modal.input());

    for (const auto& entry : state.selected) {
        if (!entry->isFile()) continue;

        std::ifstream file (fileView.wd/entry->path);
        std::string line;
        while (std::getline(file, line))
            target << line << '\n';

        file.close();
    }

    target.close();
    modal.destroy();
}

std::unique_ptr<Action> ConcatAction::clone() const {
    return std::make_unique<ConcatAction>(*this);
}

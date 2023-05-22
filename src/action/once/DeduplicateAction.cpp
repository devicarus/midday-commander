//
// Created by Vojtěch Pašek on 22.05.2023.
//

#include "DeduplicateAction.h"

void DeduplicateAction::executeAction(FileView& fileView, State&) {
    auto target = fileView.getCurrent().at(fileView.cursor);
    if (!target->isFile()) return;

    auto target_size = file_size(target->path);
    auto target_hash = Utility::getHash(target->path);
    for (const auto& entry : fileView.getCurrent(true)) {
        if (target->path != entry->path && entry->isFile()
            && file_size(entry->path) == target_size
            && Utility::getHash(entry->path) == target_hash) {
            auto filename = entry->path.filename();
            entry->remove();
            std::filesystem::create_symlink(target->path, entry->path);
        }
    }
}

std::unique_ptr<Action> DeduplicateAction::clone() const {
    return std::make_unique<DeduplicateAction>(*this);
}

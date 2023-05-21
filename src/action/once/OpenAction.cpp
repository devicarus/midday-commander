//
// Created by Vojtěch Pašek on 19.05.2023.
//

#include "OpenAction.h"
#include "../../interface/Modal.h"

void OpenAction::executeAction(FileView& fileView, State&) {
    auto target = fileView.getCurrent().at(fileView.cursor);

    try {
        if (target->isFolder())
            fileView.cd(target->path);

    } catch (const std::filesystem::filesystem_error& error) {
        Modal modal(3, 27);
        switch(error.code().value()) {
            case 62: // error code for circular symlinks on MacOS
            case 40: // error code for circular symlinks on Debian (seems like it's different for some reason)
                modal
                .show()
                .message(" Ooops, circular symlink ")
                .destroy();
                break;
            default: throw error;
        }
    }
}

std::unique_ptr<Action> OpenAction::clone() const {
    return std::make_unique<OpenAction>(*this);
}

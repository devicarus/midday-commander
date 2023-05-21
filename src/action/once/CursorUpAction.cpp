//
// Created by Vojtěch Pašek on 19.05.2023.
//

#include "CursorUpAction.h"

void CursorUpAction::executeAction(FileView& fileView, State&) {
    if (fileView.cursor > 0)
        fileView.cursor--;

    if (fileView.cursor < fileView.scroll_cursor)
        fileView.scroll_cursor = fileView.cursor;
}

std::unique_ptr<Action> CursorUpAction::clone() const {
    return std::make_unique<CursorUpAction>(*this);
}

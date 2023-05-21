//
// Created by Vojtěch Pašek on 19.05.2023.
//

#include "CursorDownAction.h"

#include "ncurses.h"

void CursorDownAction::executeAction(FileView& fileView, State&) {
    if (fileView.getCurrent().size() > fileView.cursor + 1)
        fileView.cursor++;

    if (fileView.cursor >= fileView.scroll_cursor + LINES)
        fileView.scroll_cursor = fileView.cursor - LINES + 1;
}

std::unique_ptr<Action> CursorDownAction::clone() const {
    return std::make_unique<CursorDownAction>(*this);
}

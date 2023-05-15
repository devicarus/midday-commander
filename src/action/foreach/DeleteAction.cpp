//
// Created by Vojtěch Pašek on 11.05.2023.
//

#include "ncurses.h"

#include "DeleteAction.h"

void DeleteAction::executeAction(Entry* entry) {
    // testing placeholder
    printw(("deleting " + entry->path.filename().string() + "\n").c_str());
}

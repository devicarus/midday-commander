//
// Created by Vojtěch Pašek on 13.05.2023.
//

#include "Entry.h"

Entry::Entry(std::filesystem::path path) : path(std::move(path)) {}

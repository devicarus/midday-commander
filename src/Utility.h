//
// Created by Vojtěch Pašek on 19.05.2023.
//

#ifndef MIDDAY_COMMANDER_UTILITY_H
#define MIDDAY_COMMANDER_UTILITY_H

#include <string>

#include "entry/Entry.h"

class Utility {
public:
    static std::string escape(const std::string& str);
    static std::shared_ptr<Entry> makeEntry(const std::filesystem::path& path);
};


#endif //MIDDAY_COMMANDER_UTILITY_H

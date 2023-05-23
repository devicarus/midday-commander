//
// Created by Vojtěch Pašek on 19.05.2023.
//

#ifndef MIDDAY_COMMANDER_UTILITY_H
#define MIDDAY_COMMANDER_UTILITY_H

#include <string>

#include "entry/Entry.h"

/**
 * @brief A set of utility functions
 */
class Utility {
public:
    /**
     * @brief Escapes a string so it can be printed
     */
    static std::string escape(const std::string& str);

    /**
     * @brief Makes the correct entry object based on it's path
     */
    static std::shared_ptr<Entry> makeEntry(const std::filesystem::path& path);

    /**
     * @brief Generates an MD5 hash of a file
     */
    static std::string getHash(const std::filesystem::path& path);
};


#endif //MIDDAY_COMMANDER_UTILITY_H

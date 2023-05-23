//
// Created by Vojtěch Pašek on 24.05.2023.
//

#ifndef MIDDAY_COMMANDER_CONFIG_H
#define MIDDAY_COMMANDER_CONFIG_H

#include <filesystem>

#include "interface/Theme.h"

class Config {
public:
    explicit Config(const std::filesystem::path& path = std::string{getenv("HOME")} + "/.midday.json");

    Theme theme = Theme::defaultTheme;
};


#endif //MIDDAY_COMMANDER_CONFIG_H

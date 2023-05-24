//
// Created by Vojtěch Pašek on 24.05.2023.
//

#include "Config.h"

#include <fstream>
#include "../libs/json.hpp"
using json = nlohmann::json;

Config::Config(const std::filesystem::path& path) {
    std::ifstream file(path);
    if (!file) return;

    auto config = json::parse(file);

    auto config_theme = config.at("theme");
    theme =  Theme{
        config_theme.value("primary", Theme::defaultTheme.primary),
        config_theme.value("secondary", Theme::defaultTheme.secondary),
        config_theme.value("background", Theme::defaultTheme.background),
        config_theme.value("accent1", Theme::defaultTheme.accent1),
        config_theme.value("accent2", Theme::defaultTheme.accent2),
        config_theme.value("accent3", Theme::defaultTheme.accent3)
    };

    file.close();
}

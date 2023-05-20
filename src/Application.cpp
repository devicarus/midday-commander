//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "Application.h"

#include "FileView.h"
#include "Interface.h"

Application::Application(Interface interface, FileView fileview, State state)
: interface(std::move(interface)), fileview(std::move(fileview)), state(std::move(state)) {}

int Application::run() {
    interface.initialize();

    while (state.running) {
        interface.render(fileview, state);
        interface.promptAction()->execute(fileview, state);
    }

    interface.stop();
    return 0;
}
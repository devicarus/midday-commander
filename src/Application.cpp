//
// Created by Vojtěch Pašek on 11.05.2023.
//
#include "Application.h"


Application::Application(Interface interface, FileView fileView, State state)
: interface(std::move(interface)), fileView(std::move(fileView)), state(std::move(state)) {}

int Application::run() {
    interface.initialize();

    while (state.running) {
        interface.render(fileView, state);
        interface.promptAction()->execute(fileView, state);
    }

    interface.stop();
    return 0;
}
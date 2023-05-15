//
// Created by Vojtěch Pašek on 11.05.2023.
//

#ifndef MIDDAY_COMMANDER_APPLICATION_H
#define MIDDAY_COMMANDER_APPLICATION_H

#include "Interface.h"
#include "State.h"

class Application {
public:
    Application(Interface interface, FileView fileview, State state);
    int run();
private:
    Interface interface;
    FileView fileview;
    State state;
};


#endif //MIDDAY_COMMANDER_APPLICATION_H

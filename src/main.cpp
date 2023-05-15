#include "Application.h"
#include "action/interface/QuitAction.h"
#include "action/foreach/DeleteAction.h"

int main() {
    return Application{
            Interface{}
            .addHotkey('q', new QuitAction{})
            .addHotkey('d', new DeleteAction{}),
            FileView{std::string{getenv("HOME")} + "/School"}, // for testing
            State{}
    }.run();
}

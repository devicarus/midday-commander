#include "Application.h"

#include "action/once/QuitAction.h"
#include "action/once/CursorDownAction.h"
#include "action/once/CursorUpAction.h"
#include "action/once/OpenAction.h"
#include "action/once/GoBackAction.h"
#include "action/once/ManualSelectAction.h"
#include "action/once/RegexSelectAction.h"
#include "action/once/UnselectAllAction.h"
#include "action/foreach/DeleteAction.h"
#include "action/foreach/CopyAction.h"
#include "action/foreach/MoveAction.h"
#include "action/once/CreateFileAction.h"
#include "action/once/SelectByContentAction.h"
#include "action/once/DeduplicateAction.h"
#include "action/once/ConcatAction.h"
#include "action/once/CreateFolderAction.h"
#include "action/once/CreateSymlinkAction.h"

#include "Config.h"


int main() {
    Config config;
    return Application{
            Interface{}
            .addHotkey('q', QuitAction{})
            .addHotkey(KEY_DOWN, CursorDownAction{})
            .addHotkey(KEY_UP, CursorUpAction{})
            .addHotkey(KEY_RETURN, OpenAction{})
            .addHotkey('b', GoBackAction{})
            .addHotkey('s', ManualSelectAction{})
            .addHotkey('f', RegexSelectAction{})
            .addHotkey('u', UnselectAllAction{})
            .addHotkey('d', DeleteAction{})
            .addHotkey('c', CopyAction{})
            .addHotkey('m', MoveAction{})
            .addHotkey('n', CreateFileAction{})
            .addHotkey('N', CreateFolderAction{})
            .addHotkey('S', CreateSymlinkAction{})
            .addHotkey('1', SelectByContentAction{})
            .addHotkey('2', DeduplicateAction{})
            .addHotkey('3', ConcatAction{})
            .setTheme(config.theme),
            FileView{},
            State{}
    }.run();
}

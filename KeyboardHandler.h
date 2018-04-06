#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "windows.h"


/**
 * @brief The KeyboardHandler class manages keyboard events. It does not need to keep track of
 * previous events, since events are sent in real time and can not be cancelled, hence its
 * static methods.
 */
class KeyboardHandler {
    public:
        static void onUndo();
        static void onRedo();
};

#endif // KEYBOARDHANDLER_H

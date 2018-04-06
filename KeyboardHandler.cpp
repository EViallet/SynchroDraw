#include "KeyboardHandler.h"

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms646310(v=vs.85).aspx

/**
*	Sends Ctrl+Z to the active window.
*	TODO : upgrade keybd_event, which have been deprecated, to SendInput
*/
void KeyboardHandler::onUndo() {
    keybd_event(
                VK_LCONTROL,
                0,
                0,
                0);
    keybd_event(
                0x5A,
                0,
                0,
                0);
    keybd_event(
                VK_LCONTROL,
                0,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(
                0x5A,
                0,
                KEYEVENTF_KEYUP,
                0);
    /*
    LPINPUT inputs = (tagINPUT*)malloc(2*sizeof(INPUT));
    inputs[0].type = 1;
    KEYBDINPUT kbd1;
    kbd1.wVk = VK_LCONTROL; // L-CTRL
    inputs[0].ki = kbd1;

    inputs[1].type = 1;
    KEYBDINPUT kbd2;
    kbd2.wVk = 0x5A; // Z
    inputs[1].ki = kbd2;
    SendInput(2, inputs, sizeof(INPUT));

    kbd1.dwFlags = KEYEVENTF_KEYUP;
    inputs[0].ki = kbd1;

    kbd2.dwFlags = KEYEVENTF_KEYUP;
    inputs[1].ki = kbd2;
    SendInput(2, inputs, sizeof(INPUT));
    */
}

/**
*	Sends Ctrl+Y to the active window.
*	TODO : upgrade keybd_event, which have been deprecated, to SendInput
*/
void KeyboardHandler::onRedo() {
    keybd_event(
                VK_LCONTROL,
                0,
                0,
                0);
    keybd_event(
                0x59,
                0,
                0,
                0);
    keybd_event(
                VK_LCONTROL,
                0,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(
                0x59,
                0,
                KEYEVENTF_KEYUP,
                0);
    /*
    LPINPUT inputs = (tagINPUT*)malloc(2*sizeof(INPUT));
    inputs[0].type = 1;
    KEYBDINPUT kbd1;
    kbd1.wVk = VK_LCONTROL; // L-CTRL
    inputs[0].ki = kbd1;

    inputs[1].type = 1;
    KEYBDINPUT kbd2;
    kbd2.wVk = 0x59; // Y
    inputs[1].ki = kbd2;
    SendInput(2, inputs, sizeof(INPUT));

    kbd1.dwFlags = KEYEVENTF_KEYUP;
    inputs[0].ki = kbd1;

    kbd2.dwFlags = KEYEVENTF_KEYUP;
    inputs[1].ki = kbd2;
    SendInput(2, inputs, sizeof(INPUT));
    */
}

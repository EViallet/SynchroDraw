#include "MouseHandler.h"

/**
 * @brief MouseHandler::MouseHandler is recquired by the QObject inheritance. It also search for the local screen resolution.
 */
MouseHandler::MouseHandler() {
    w = QApplication::desktop()->screenGeometry().width();
    h = QApplication::desktop()->screenGeometry().height();
}

/**
 * @brief MouseHandler::onMouseMove sets the cursor position.
 * @param x Horizontal coord of the event
 * @param y Vertical coord of the event
 */
void MouseHandler::onMouseMove(int x, int y) {
    float x2 = (float)x*w/(float)1920.0;
    float y2 = (float)y*h/(float)1080.0;

    QApplication::desktop()->cursor().setPos(x2,y2);
}

/**
 * @brief MouseHandler::onMouseClic sends a KEY_DOWN event from L mouse button.
 * @param x Horizontal coord of the event
 * @param y Vertical coord of the event
 * TODO updrade mouse_event, which have been deprecated, to SendInput
 */
void MouseHandler::onMouseClic(int x, int y) {
    onMouseMove(x,y);
    left = true;
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, 1, 1, 0, 0);
}

/**
 * @brief MouseHandler::onMouseRelease sends a KEY_UP event for both L and R mouse buttons.
 * @param x Horizontal coord of the event
 * @param y Vertical coord of the event
 * TODO updrade mouse_event, which have been deprecated, to SendInput
 */
void MouseHandler::onMouseRelease(int x, int y) {
    onMouseMove(x,y);
    if(left)
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, 1, 1, 0, 0);
    if(right)
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP, 1, 1, 0, 0);
    left = false;
    right = false;
}

/**
 * @brief MouseHandler::onMouseRClic sends a KEY_DOWN event from R mouse button.
 * @param x Horizontal coord of the event
 * @param y Vertical coord of the event
 * TODO updrade mouse_event, which have been deprecated, to SendInput
 */
void MouseHandler::onMouseRClic(int x, int y) {
    onMouseMove(x,y);
    right = true;
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN, 1, 1, 0, 0);
}


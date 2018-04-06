#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <QDebug>
#include <QApplication>
#include <QObject>
#include <QScreen>
#include <windows.h>
#include <QDesktopWidget>

/**
 * @brief The MouseHandler class keeps track of held mouse buttons and cursor position. It also
 * converts 1920*1080 coordinates into local screen resolution coordinates.
 */
class MouseHandler : public QObject {
    Q_OBJECT
    public:
        MouseHandler();
    public slots:
        void onMouseMove(int x, int y);
        void onMouseClic(int x, int y);
        void onMouseRClic(int x, int y);
        void onMouseRelease(int x, int y);
private:
        float w;    /// local resolution width
        float h;    /// local resolution height

        bool left = false;  /// is left mouse button being held
        bool right = false; /// is right mouse button being held
};

#endif // MOUSEHANDLER_H

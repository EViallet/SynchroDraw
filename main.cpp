#include <QApplication>
#include "Server.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Server *server = new Server(&a);
    MouseHandler *mouse = new MouseHandler;
    KeyboardHandler *keybd = new KeyboardHandler;

    /** MOUSE */
    server->connect(server,SIGNAL(mouseMove(int,int)),mouse,SLOT(onMouseMove(int,int)));
    server->connect(server,SIGNAL(mouseClic(int,int)),mouse,SLOT(onMouseClic(int,int)));
    server->connect(server,SIGNAL(mouseRClic(int,int)),mouse,SLOT(onMouseRClic(int,int)));
    server->connect(server,SIGNAL(mouseReleased(int,int)),mouse,SLOT(onMouseRelease(int,int)));

    server->startServer();

    return a.exec();
}

#ifndef SERVER_H
#define SERVER_H



#define SEP_PACKET "<PCK>"
/** MOUSE*/
#define SEP_UP "~"
#define SEP_MOVED "&"
#define SEP_CLICKED "#"
#define SEP_RCLICKED "-"
#define SEP_RELEASED "="
#define SEP_XY "+"
/** PIC */
#define SEP_REFRESH "~"
#define SEP_PIC "<PIC>"
#define SEP_ENDPIC "</PIC>"
/** KEYBD */
#define SEP_CANCEL "<CTZ>"
#define SEP_REDO "<CTY>"

#include <QNetworkInterface>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDesktopWidget>
#include "ScreenViewer.h"
#include "KeyboardHandler.h"

class Server : public QObject {
    Q_OBJECT
    public:
        Server(QApplication*);

    signals:
        /** MOUSE*/
        void mouseMove(int,int);
        void mouseClic(int,int);
        void mouseRClic(int,int);
        void mouseReleased(int,int);
        /** KEYBD */
        void undo();
        void redo();
    public slots:
        void startServer();
        void write(QString data);
    private slots:
        void onNewConnection();
        void onReadyRead();
        void onStateChanged(QAbstractSocket::SocketState state);
        bool isComplete(QString str);
        bool isCmdComplete(QString str);
        void servError(QAbstractSocket::SocketError err);
private:
        ScreenViewer *screen;
        QApplication *a;
        QTcpServer *server;
        QTcpSocket *socket;
        QString buffer;

};

#endif // SERVER_H

#include "Server.h"

Server::Server(QApplication *a) {
    server = new QTcpServer;
    screen = new ScreenViewer(a);
    connect(server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    connect(server,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(servError(QAbstractSocket::SocketError)));
}

void Server::servError(QAbstractSocket::SocketError err) {
    qDebug() << err;
}

void Server::startServer() {
    QHostAddress ip;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             ip = address;
    }

    if(server->listen(ip))
        qDebug() << "Server listening on " << server->serverAddress().toString() << " on port " << server->serverPort();
    else
        qDebug() << "Error : " << strerror(errno);
}

void Server::onNewConnection() {
    qDebug() << "Connected.";
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onStateChanged(QAbstractSocket::SocketState)));
    server->close();
    if(socket->canReadLine())
        socket->readAll();
    write(screen->sendScreen());
}

void Server::onStateChanged(QAbstractSocket::SocketState state) {
    if(state==QAbstractSocket::UnconnectedState)
        startServer();
}

void Server::onReadyRead() {
    QString str (socket->readAll());

    if(str.contains(SEP_REFRESH)) {
        write(screen->sendScreen());
        return;
    } else if(str.contains(SEP_CANCEL)) {
        KeyboardHandler::onUndo();
        return;
    }else if(str.contains(SEP_REDO)) {
        KeyboardHandler::onRedo();
        return;
    }

    bool valid = false;
    QString read = "";


    if(!isComplete(str)) {
        buffer.append(str);
        if(!isComplete(buffer))
            return;
        else {
            read = buffer;
            valid = true;
            buffer = "";
        }
    } else {
        read = str;
        valid = true;
    }

    if(valid) {
        QStringList cmds = read.split(SEP_PACKET);
        for(int i=1; i<cmds.length(); i++) {
            QString strCmd = cmds.at(i);
            if(!isCmdComplete(strCmd)) {
                buffer.append(strCmd);
                break;
            }
            strCmd = strCmd.replace(SEP_PACKET,"");
            if (strCmd.contains(SEP_MOVED)) {
                strCmd = strCmd.replace(SEP_MOVED,"");
                int x = strCmd.section(SEP_XY, 1, 1).replace(SEP_XY,"").toInt();
                int y = strCmd.section(SEP_XY,2,2).replace(SEP_XY,"").toInt();

                emit(mouseMove(x,y));

            } else if(strCmd.contains(SEP_CLICKED)) {
                strCmd = strCmd.replace(SEP_CLICKED,"");
                int x = strCmd.section(SEP_XY, 1, 1).replace(SEP_XY,"").toInt();
                int y = strCmd.section(SEP_XY,2,2).replace(SEP_XY,"").toInt();

                emit(mouseClic(x,y));

            } else if(strCmd.contains(SEP_RCLICKED)) {
                strCmd = strCmd.replace(SEP_RCLICKED,"");
                int x = strCmd.section(SEP_XY, 1, 1).replace(SEP_XY,"").toInt();
                int y = strCmd.section(SEP_XY,2,2).replace(SEP_XY,"").toInt();

                emit(mouseRClic(x,y));
            } else if(strCmd.contains(SEP_RELEASED)) {
                strCmd = strCmd.replace(SEP_RELEASED,"");
                int x = strCmd.section(SEP_XY, 1, 1).replace(SEP_XY,"").toInt();
                int y = strCmd.section(SEP_XY,2,2).replace(SEP_XY,"").toInt();

                emit(mouseReleased(x,y));
            }
        }
    }
}


bool Server::isComplete(QString str) {
    return str.count(SEP_PACKET)>0&&str.count(SEP_XY)>=2;
}

bool Server::isCmdComplete(QString str) {
    return str.count(SEP_XY)==2;
}

void Server::write(QString data) {
    if(socket->state()==QAbstractSocket::ConnectedState)
        socket->write(QString(SEP_PACKET).append(data).toLatin1());
}



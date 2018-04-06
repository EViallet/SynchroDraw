#ifndef SCREENVIEWER_H
#define SCREENVIEWER_H

#define SEP_PIC "<PIC>"
#define SEP_ENDPIC "</PIC>"

#include <QObject>
#include <QApplication>
#include <QScreen>
#include <QPixmap>
#include <QBuffer>

class ScreenViewer : public QObject {
    Q_OBJECT
    public:
        ScreenViewer(QApplication*);

    signals:

    public slots:
        QString sendScreen();
    private:
        QApplication*a;
};

#endif // SCREENVIEWER_H

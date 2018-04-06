#include "ScreenViewer.h"

ScreenViewer::ScreenViewer(QApplication* a) {
    this->a = a;
}

QString ScreenViewer::sendScreen() {
    QScreen *screen = a->primaryScreen();

    QPixmap screenshot = screen->grabWindow(0);
    screenshot = screenshot.scaled(1920,1080,Qt::IgnoreAspectRatio);
    // base64 conversion
    QByteArray ba;
    QBuffer bu(&ba);
    screenshot.save(&bu, "PNG");

    QString imgBase64 = ba.toBase64();

    // sending
    QString img = "";
    img.append(SEP_PIC).append(imgBase64).append(SEP_ENDPIC);
    return img;
}

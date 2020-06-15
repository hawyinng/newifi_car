#include "clientdialog.h"
#include <QApplication>
#include <QTextCodec>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    /*
    QSize iconSize(32, 32);
    QScreen *screen = a.primaryScreen();
    QFont f = a.font();
    int pixelSize = (f.pointSize() * screen->logicalDotsPerInch()) / 72;
    QSize screenSize = screen->size();
    qDebug() << "screenSize.width()" << screenSize.width() << "\n" << "screenSize.height()" << screenSize.height();

    if(screenSize.width() > 960 || screenSize.height() > 960)
    {
        iconSize *= ((qreal)pixelSize) / 20;
    }
    */

    Clientdialog w;
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    MainWindow w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft YaHei UI", 10));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    MainWindow w;
    w.show();

    return a.exec();
}

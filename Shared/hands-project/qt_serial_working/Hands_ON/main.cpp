#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QSplashScreen>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
//    w.show();

    return a.exec();
}

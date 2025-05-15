#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    ///123
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

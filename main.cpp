#include <QApplication>
#include <ctime>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

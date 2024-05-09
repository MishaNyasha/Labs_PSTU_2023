#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include <iostream>
#include "mainwindow.h"
#include <vector>
#include <algorithm>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "QtGraphs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtGraphs w;
    w.show();
    return a.exec();
}

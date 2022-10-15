#include "danmuwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    danmuWidget w;
    w.show();
    return a.exec();
}

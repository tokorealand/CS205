#include "statisticsgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StatisticsGui w;
    w.show();

    return a.exec();
}

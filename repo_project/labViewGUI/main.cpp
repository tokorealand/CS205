#include "labviewgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    labViewGUI w;
    w.show();

    return a.exec();
}

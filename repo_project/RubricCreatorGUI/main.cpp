#include "rubriccreatorgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RubricCreatorGUI w;
    w.show();

    return a.exec();
}

#include "add_students_gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    add_students_gui w;
    w.show();

    return a.exec();
}

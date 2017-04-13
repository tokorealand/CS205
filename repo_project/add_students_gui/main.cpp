#include "add_students_gui.h"
#include <QApplication>
#include <../grader/grader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Grader *grad = new Grader();
    add_students_gui w(0,grad);
    w.show();

    return a.exec();
}

#include "selectiongui.h"
#include <QApplication>
#include <../grader/grader.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Grader *grad = new Grader();

    selectiongui w(0,grad);
    w.show();

    return a.exec();
}

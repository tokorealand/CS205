#ifndef ADD_STUDENTS_GUI_H
#define ADD_STUDENTS_GUI_H

#include <QWidget>
#include "../grader/section.h"
#include "../grader/student.h"
#include "../grader/dbtable.h"
#include "../grader/dbtool.h"
#include "../grader/lab.h"
#include "../grader/class.h"
#include "../grader/component.h"
#include "../grader/commentengine.h"
#include "../grader/grader.h"
#include "../grader/fileparser.h"

namespace Ui {
class add_students_gui;
}

class add_students_gui : public QWidget
{
    Q_OBJECT

public:
    explicit add_students_gui(QWidget *parent = 0, Grader* aGrader = NULL);
    ~add_students_gui();

private slots:
    void on_selectButton_clicked();

    void on_mainMenuButton_clicked();

private:
    Ui::add_students_gui *ui;
    Grader* grader;
};

#endif // ADD_STUDENTS_GUI_H

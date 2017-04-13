#ifndef SELECTIONGUI_H
#define SELECTIONGUI_H

#include <QWidget>
#include <iostream>
#include <QObject>
#include <QList>
#include <QSignalMapper>
#include <QListWidget>
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
class selectiongui;
class Lab;
class Student;
class Section;
class Class;
}

class selectiongui : public QWidget
{
    Q_OBJECT

public:
    explicit selectiongui(QWidget *parent = 0, Grader *aGrader =NULL);
    ~selectiongui();

private slots:
    void on_cs_clicked();

    void on_ss_clicked();

    void on_sts_clicked();

    void on_ls_clicked();

private:
    Ui::selectiongui *ui;
    Grader *grader;
    Class *cclass;
    Section *csection;
    Student *cstudent;
    Lab *clab;



};

#endif // SELECTIONGUI_H

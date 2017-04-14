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
    bool lab_selected();
    bool exit_pressed();

    Lab* select_lab();
    Class*  select_class();



private slots:


    void on_classlist_doubleClicked(const QModelIndex &index);

    void on_sectionlist_doubleClicked(const QModelIndex &index);

    void on_studenlist_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_lablist_doubleClicked(const QModelIndex &index);

private:
    Ui::selectiongui *ui;
    Grader *grader;
    Class *cclass;
    Section *csection;
    Student *cstudent;
    Lab *clab;

    bool labselect = false;
    bool exit = false;


};

#endif // SELECTIONGUI_H

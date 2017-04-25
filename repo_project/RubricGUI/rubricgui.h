#ifndef RUBRICGUI_H
#define RUBRICGUI_H

#include <QWidget>
#include <iostream>
#include <QObject>
#include <QSignalMapper>
#include "../grader/lab.h"
#include "../grader/grader.h"
#include "../addlabsGUI/addlabsgui.h"
#include "../CommentGUI/dialog.h"
#include "../grader/year.h"
#include "../grader/semester.h"
#include "../grader/component.h"
#include "../grader/dbtable.h"
#include "../grader/dbtool.h"

namespace Ui {
class RubricGUI;
}

class RubricGUI : public QWidget
{
    Q_OBJECT

public:
    explicit RubricGUI(QWidget *parent = 0, Grader* grad = nullptr);
    ~RubricGUI();

    void display_years();
    void display_colors();

private slots:
    void on_yearSelect_activated(const QString &arg1);

    void on_semesterSelect_activated(const QString &arg1);

    void on_classSelect_activated(const QString &arg1);


    void on_createRubric_clicked();

    void on_addSection_clicked();



    void on_rubricSelect_activated(const QModelIndex &index);

    void on_rubricsectionSelect_activated(const QModelIndex &index);

private:
    Ui::RubricGUI *ui;
    Component* selected_component =nullptr;
    Lab* selected_lab = nullptr;
    Student* selected_student = nullptr;
    Class* selected_class = nullptr;
    Section* selected_section =nullptr;
    Year* selected_year =nullptr;
    Semester* selected_semester =nullptr;
    RubricObject* selected_rubric = nullptr;
    RubricSection* selected_rubric_section = nullptr;
    Grader *grad;
};

#endif // RUBRICGUI_H
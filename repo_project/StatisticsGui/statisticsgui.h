#ifndef STATISTICSGUI_H
#define STATISTICSGUI_H

#include <QWidget>
#include <iostream>
#include <QObject>
#include <QSignalMapper>
#include "../grader/lab.h"
#include "../grader/grader.h"
#include "../grader/year.h"
#include "../grader/semester.h"
#include "../grader/component.h"

#include <QWidget>

namespace Ui {
class StatisticsGui;
}

class StatisticsGui : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsGui(QWidget *parent = 0, Grader *grad = nullptr);
    ~StatisticsGui();

    void display_years();

private slots:
    void on_calcbutton_clicked();
    void on_doneButton_clicked();
    void on_yearSelect_activated(const QString &arg1);
    void on_semesterSelect_activated(const QString &arg1);
    void on_classSelect_activated(const QString &arg1);
    void on_sectionSelect_activated(const QString &arg1);

private:
    Ui::StatisticsGui *ui;
    Component* selected_component =nullptr;
    Lab* selected_lab = nullptr;
    Student* selected_student = nullptr;
    Class* selected_class = nullptr;
    Section* selected_section =nullptr;
    Year* selected_year =nullptr;
    Semester* selected_semester =nullptr;
    Grader *grad;
};

#endif // STATISTICSGUI_H

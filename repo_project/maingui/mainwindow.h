#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


class Grader;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
        void build_tabs();
        void display_java_text();
        void populate_existing_labs();

private slots:

    void on_actionLoad_New_Lab_triggered();

    void on_actionAdd_Students_triggered();

    void on_actionComment_triggered();

    void on_displayButton_clicked();

    void on_actionLoad_Lab_triggered();

    void click_lab_in_existing_labs_menu();


    void on_pushButton_clicked();

    void on_classlist_doubleClicked(const QModelIndex &index);

    void on_sectionlist_doubleClicked(const QModelIndex &index);

    void on_studentlist_doubleClicked(const QModelIndex &index);

    void on_lablist_doubleClicked(const QModelIndex &index);

    void on_disjava_doubleClicked(const QModelIndex &index);

    void on_years_activated(const QString &arg1);

    void on_semesters_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Component* selected_component =nullptr;
    Lab* selected_lab = nullptr;
    Student* selected_student = nullptr;
    Class* selected_class = nullptr;
    Section* selected_section =nullptr;
    Year* selected_year =nullptr;
    Semester* selected_semester =nullptr;
    Grader *grad;

    void display_classes();
    void display_years();


};

#endif // MAINWINDOW_H

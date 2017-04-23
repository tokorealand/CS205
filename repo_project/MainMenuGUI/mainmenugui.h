#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

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
#include "../grader/dbtable.h"
#include "../grader/dbtool.h"

class Grader;
namespace Ui {
class MainMenuGUI;
}

class MainMenuGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuGUI(QWidget *parent = 0);
    ~MainMenuGUI();

    void display_years();

private slots:
    void on_yearSelect_activated(const QString &arg1);

    void on_actionAdd_New_Labs_triggered();

    void on_Refresh_clicked();

    void on_semesterSelect_activated(const QString &arg1);

    void on_classSelect_activated(const QString &arg1);

    void on_sectionSelect_activated(const QString &arg1);

    void on_labSelect_activated(const QString &arg1);

    void on_studentSelect_activated(const QString &arg1);


    void on_componentSelect_activated(const QModelIndex &index);

    void display_component_text();

    void display_comment_text();



    void on_saveAndExit_clicked();

    void on_checkBox_toggled(bool checked);

    void on_actionComment_triggered();

private:
    Ui::MainMenuGUI *ui;
    Component* selected_component =nullptr;
    Lab* selected_lab = nullptr;
    Student* selected_student = nullptr;
    Class* selected_class = nullptr;
    Section* selected_section =nullptr;
    Year* selected_year =nullptr;
    Semester* selected_semester =nullptr;
    Grader *grad;
};

#endif // MAINMENUGUI_H

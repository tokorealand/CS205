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

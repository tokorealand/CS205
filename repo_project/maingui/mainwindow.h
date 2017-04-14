#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QSignalMapper>
#include "../grader/lab.h"
#include "../grader/grader.h"
#include "../add_students_gui/add_students_gui.h"
#include "../addlabsGUI/addlabsgui.h"
#include "../CommentGUI/dialog.h"
#include "../selectiongui/selectiongui.h"
#include <QListWidget>

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

private:
    Ui::MainWindow *ui;
    Lab* selected_lab = nullptr;
    Class* selected_class = nullptr;
    Grader *grad;

};

#endif // MAINWINDOW_H

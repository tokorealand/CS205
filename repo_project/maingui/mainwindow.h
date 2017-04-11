#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QSignalMapper>
#include "../addnewlabsgui/widgeta.h"
#include "../addnewlabsgui/ui_widget.h"
#include "../AddStudentsGUI1/addstudentsgui.h"
#include "../AddStudentsGUI1/ui_addstudentsgui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void add_existing_lab_list();
    QString labSelect;
    QStringList labStringList;
    QSignalMapper signalMapper;
    void build_tabs();
    QString selected_lab_string;
    QAction *selected_lab;

public slots:
    void load_lab(); // needs a new name I think
    void add_new_labs();
    void add_students();
    void load_random_lab();
    void comment();
    void highlight();

    //LAB CONTAINER OBJECT -- holds the lab objects

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

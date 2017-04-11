#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "../grader/lab.h"
#include "../grader/grader.h"

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


private slots:

    void on_actionLoad_New_Lab_triggered();



    void on_actionAdd_Students_triggered();

    void on_displayButton_clicked();

private:
    Ui::MainWindow *ui;
    Lab* selected_lab = nullptr;
    Grader *grad;
};

#endif // MAINWINDOW_H

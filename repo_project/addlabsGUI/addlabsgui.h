#ifndef ADDLABSGUI_H
#define ADDLABSGUI_H

#include <QWidget>
#include "../grader/grader.h"
#include "../grader/fileparser.h"
#include "../RubricCreatorGUI/rubriccreatorgui.h"
#include <QFileDialog>

namespace Ui {

class Lab;
class RubricObject;

class AddLabsGUI;
}

class AddLabsGUI : public QWidget
{
    Q_OBJECT

public:
    explicit AddLabsGUI(QWidget *parent = 0, Grader* aGrader = NULL);
    ~AddLabsGUI();
    void add_rubric_to_labs();

private slots:
    void on_selectButton_clicked();

//    void on_doneButton_clicked();

//    void on_addRubricButton_clicked();

    void on_browseButton_clicked();

private:
    Grader* grader;
    Ui::AddLabsGUI *ui;
    string componentid;
    Controller* controller;
    vector<string> labIDList;
};

#endif // ADDLABSGUI_H

#ifndef ADDLABSGUI_H
#define ADDLABSGUI_H

#include <QWidget>
#include "../grader/grader.h"
#include "../grader/fileparser.h"

namespace Ui {
class AddLabsGUI;
}

class AddLabsGUI : public QWidget
{
    Q_OBJECT

public:
    explicit AddLabsGUI(QWidget *parent = 0, Grader* aGrader = NULL);
    ~AddLabsGUI();

private slots:
    void on_selectButton_clicked();

    void on_doneButton_clicked();

private:
    Grader* grader;
    Ui::AddLabsGUI *ui;
};

#endif // ADDLABSGUI_H

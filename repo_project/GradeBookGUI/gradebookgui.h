#ifndef GRADEBOOKGUI_H
#define GRADEBOOKGUI_H

#include <QWidget>

namespace Ui {
class GradeBookGUI;
}

class GradeBookGUI : public QWidget
{
    Q_OBJECT

public:
    explicit GradeBookGUI(QWidget *parent = 0);
    ~GradeBookGUI();

private:
    Ui::GradeBookGUI *ui;
};

#endif // GRADEBOOKGUI_H

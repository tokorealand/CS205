#ifndef RUBRICCREATORGUI_H
#define RUBRICCREATORGUI_H

#include <QWidget>
#include "../grader/rubricobject.h"
#include "../grader/class.h"
#include "../grader/grader.h"

using namespace std;

namespace Ui {
class RubricCreatorGUI;
}

class RubricCreatorGUI : public QWidget
{
    Q_OBJECT

public:
    explicit RubricCreatorGUI(QWidget *parent = 0, Grader *grader = nullptr);
    ~RubricCreatorGUI();
    RubricObject* get_rubric();

    //PRIVATE ?
    QStringList sections;
    void display_sections();
    QStringList pointVals;
    QStringList colors;
    double totalPoints = 0.0;

private slots:
    void on_doneButton_clicked();
    void on_removeSelectedButton_clicked();
    void on_addSectionButton_clicked();

private:
    Ui::RubricCreatorGUI *ui;
    Grader* grader;
    RubricObject *r;
};

#endif // RUBRICCREATORGUI_H

#ifndef RUBRICCREATORGUI_H
#define RUBRICCREATORGUI_H

#include <QWidget>

using namespace std;

namespace Ui {
class RubricCreatorGUI;
}

class RubricCreatorGUI : public QWidget
{
    Q_OBJECT

public:
    explicit RubricCreatorGUI(QWidget *parent = 0);
    ~RubricCreatorGUI();

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
};

#endif // RUBRICCREATORGUI_H

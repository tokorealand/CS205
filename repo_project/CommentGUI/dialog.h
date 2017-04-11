#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "../grader/grader.h"
#include "../grader/fileparser.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, Grader* aGrader = NULL, Lab *aLab = nullptr);
    ~Dialog();

private slots:
    void on_doneButton_clicked();
    void populate();
    void populate_comment_list();


    void on_commentText_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    Grader* grader;
    Lab *lab;
    QStringList commentQStringList;

};

#endif // DIALOG_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "../grader/grader.h"
#include "../grader/fileparser.h"
#include "../grader/component.h"
#include "../grader/class.h"
#include "../grader/lab.h"
#include "../grader/rubricobject.h"
#include "../grader/rubricsection.h"

/**
 * @class Dialog
 *
 * the comment gui for gathering info from the user and using it to create a
 * comment object.
 */
namespace Ui {
class Dialog;
}

class Dialog : public QDialog{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, Grader* aGrader = NULL, Lab *aLab = nullptr, Component *aComponent = nullptr, Class* aclass =nullptr);
    ~Dialog();

private slots:
    void on_doneButton_clicked();
    void populate();
    void populate_comment_list();
    void on_commentText_textChanged(const QString &arg1);
    void on_commentList_clicked(const QModelIndex &index);

private:
    Ui::Dialog *ui;
    Grader* grader;
    Lab *lab;
    Class *aclass;
    QStringList commentQStringList;
    Component *component;
};

#endif // DIALOG_H

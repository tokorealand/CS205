#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_doneButton_clicked();
    void populate();
    void populate_comment_list();


    void on_commentText_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    QStringList commentQStringList;

};

#endif // DIALOG_H

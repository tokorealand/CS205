#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../grader/grader.h"
#include "../grader/fileparser.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0, Grader* = NULL);
    ~Widget();

private slots:
    void on_select_clicked();

    void on_mainMenu_clicked();

private:
    Ui::Widget *ui;
    Grader* grader;

};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //LabReader get_lab_reader();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    //LabReader labReader;
    //Container labReaderHolder;
    //RubricCreatorGui rcg;
    //RubricObject rubriObject;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

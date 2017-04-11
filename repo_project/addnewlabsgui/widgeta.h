#ifndef WIDGETA_H
#define WIDGETA_H

#include <QWidget>

namespace Ui {
class Widget;
}

class WidgetA : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetA(QWidget *parent = 0);
    ~WidgetA();
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

#endif // WIDGETA_H

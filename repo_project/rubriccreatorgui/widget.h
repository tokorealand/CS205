#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    QStringList sections;
    void display_sections();
    QStringList pointVals;
    QStringList colors;
    double totalPoints = 0.0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

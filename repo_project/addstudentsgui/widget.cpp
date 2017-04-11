#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, int i) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//add button
void Widget::on_pushButton_clicked(){
    //ui->listWidget->addItem(ui->textEdit->toPlainText());
}

//done button
void Widget::on_pushButton_2_clicked(){
    //save the list
    close();
}

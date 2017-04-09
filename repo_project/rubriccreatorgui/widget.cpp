#include "widget.h"
#include "ui_widget.h"
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::display_sections(){

    ui->listWidget->clear();
    ui->listWidget->addItems(sections);

    ui->listWidget_2->clear();
    ui->listWidget_2->addItems(pointVals);

    ui->listWidget_3->clear();
    ui->listWidget_3->addItems(colors);

    ui->label_5->setText(QString("%1").arg(totalPoints));

}

//add section
void Widget::on_pushButton_clicked(){

    //add the rubric section
    QString newSection = ui->textEdit->toPlainText();
    sections.append(newSection);

    //add the point values
    QString newPointVal = ui->doubleSpinBox->cleanText();
    pointVals.append(newPointVal);

    //add the colors
    QString newColor = ui->comboBox->currentText();
    colors.append(newColor);

    totalPoints = totalPoints + ui->doubleSpinBox->value();

    display_sections();
}

//done button
void Widget::on_pushButton_2_clicked(){
    //create a rubric object

    //sections - contains all the rubric sections
    //pointValues - contains all the point values
    //colors - contains all the colors
    //totalPoints - the total points in the rubric

    close();//exit gui

}

//remove selected
void Widget::on_pushButton_3_clicked(){

    if(ui->listWidget->selectedItems().size()>0){
        sections.removeOne(ui->listWidget->selectedItems().at(0)->text());
    }
    if(ui->listWidget_2->selectedItems().size()>0){
        pointVals.removeOne(ui->listWidget_2->selectedItems().at(0)->text());

        string s = ui->listWidget_2->selectedItems().at(0)->text().toUtf8().constData();
        double d = stod(s);
        totalPoints = totalPoints - d;
    }
    if(ui->listWidget_3->selectedItems().size()>0){
        colors.removeOne(ui->listWidget_3->selectedItems().at(0)->text());
    }

    display_sections();
}


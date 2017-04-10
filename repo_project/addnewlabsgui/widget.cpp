#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setStyleSheet(
             "background-image:url(\"/home/worklu/repo_lopez_mullan_lickfeld_binici/repo_project/maingui/minb.jpg\"); background-position: center;" );
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//upload labs
void Widget::on_pushButton_3_clicked(){
    //create a lab reader object
    //labReader = new LabReader(constructor);
    //save the text inside ui.textEdit_2
    //QString path = ui->textEdit_2.text();
    //get the labs from the path and save them to some structure
            //labReaderHolder =
    //add them to the lab reader
    //for(int i = 0; i < number of labs; i++){
        //labReader.addLabs(labReaderHolder.at(i));
    //}
}

//done
void Widget::on_pushButton_clicked(){
    //save lab title
}

//add rubric
void Widget::on_pushButton_2_clicked(){
    //create and run a RubricCreatorGui - this will create a rubric object inside of it
    //get + save rubricObject from RubricCreatorGui
}

//LabReader get_lab_reader(){
    //return labReader;
//}

//RubricObject get_rubric_object(){
    //return rubricObject;
//}

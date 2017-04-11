#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, Grader* aGrader) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    grader = aGrader;
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_select_clicked()
{
  string filepath = ui->selectedPath->text().toStdString();
  vector<string> studentInfo = grader->get_file_parser()->parse_student_file(filepath);

}


void Widget::on_mainMenu_clicked()
{
    close();
}

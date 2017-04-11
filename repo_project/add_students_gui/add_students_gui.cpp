#include "add_students_gui.h"
#include "ui_add_students_gui.h"

add_students_gui::add_students_gui(QWidget *parent, Grader* aGrader) :
    QWidget(parent),
    ui(new Ui::add_students_gui)
{
    grader = aGrader;
    ui->setupUi(this);
}

add_students_gui::~add_students_gui()
{
    delete ui;
}

void add_students_gui::on_selectButton_clicked()
{
   string filepath = ui->selectedFilePath->text().toStdString();
   string studentInfo = grader->get_file_parser()->parse_student_file(filepath);

   ui->displayStudents->setPlainText(QString:: fromStdString(studentInfo));

}

void add_students_gui::on_mainMenuButton_clicked()
{
    close();
}

#include "addlabsgui.h"
#include "ui_addlabsgui.h"

AddLabsGUI::AddLabsGUI(QWidget *parent, Grader * aGrader) :
    QWidget(parent),
    ui(new Ui::AddLabsGUI)
{
    grader = aGrader;
    ui->setupUi(this);
}

AddLabsGUI::~AddLabsGUI()
{
    delete ui;
}

void AddLabsGUI::on_selectButton_clicked(){

    //save file path
    string filepath = ui->labPathText->toPlainText().toStdString();
    string labName = ui->labNameText->toPlainText().toStdString();

    //vector<string> labInfo = grader->get_file_parser()->parse_lab_file(filepath);

    //give the grader a lab name
    grader->add_lab_name(labName);
}

void AddLabsGUI::on_doneButton_clicked(){
    close();
}

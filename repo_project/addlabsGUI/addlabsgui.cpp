#include "addlabsgui.h"
#include "ui_addlabsgui.h"

class Lab;
class RubricObject;

AddLabsGUI::AddLabsGUI(QWidget *parent, Grader * aGrader) :
    QWidget(parent),
    ui(new Ui::AddLabsGUI)
{
    grader = aGrader;
    ui->setupUi(this);
}

AddLabsGUI::~AddLabsGUI(){
    delete ui;
}

void AddLabsGUI::on_selectButton_clicked(){

    //save file path
    string filepath = ui->labPathText->toPlainText().toStdString();
    labIDList = grader->get_file_parser()->parse_java_file(filepath);
    controller = grader->get_control();
     close();
    //grader->get_file_parser()->parse_java_file(filepath);
}

//void AddLabsGUI::on_doneButton_clicked(){
//  //  add_rubric_to_labs();
//}

//void AddLabsGUI::on_addRubricButton_clicked(){
//    RubricCreatorGUI *r = new RubricCreatorGUI(0, grader);
//    r->show();
//}

void AddLabsGUI::on_browseButton_clicked()
{
    ui->labPathText->clear();
    QString filename = QFileDialog::getExistingDirectory(this, tr(""), "/User",  QFileDialog::ShowDirsOnly);
    ui->labPathText->setText(filename);
}

void AddLabsGUI::add_rubric_to_labs(){

    RubricObject* rubric = grader->get_temp_rubric();
    cout << "rubric sections at 0 in add labs gui" << endl;
    cout << rubric->get_rubric_sections().at(0) << endl;

    //add the rubric to the labs
    for(int i = 0; i < labIDList.size(); i ++){
        string labID = labIDList.at(i);
        cout << "lab id in add labs gui" << endl;
        cout << labID << endl;
        cout << controller->get_lab(labID) << endl;
        controller->get_lab(labID)->add_rubric(rubric);
    }
}

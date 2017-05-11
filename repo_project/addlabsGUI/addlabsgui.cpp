#include "addlabsgui.h"
#include "ui_addlabsgui.h"

class Lab;
class RubricObject;

/**
 * @brief AddLabsGUI::AddLabsGUI
 * GUI used to input lab submissions. Select directory containing lab submission subdirectories
 * Lab submissions must be titled "firstName_lastName_class_section_labNum_semester_year"
 * @param parent
 * @param aGrader
 */
AddLabsGUI::AddLabsGUI(QWidget *parent, Grader * aGrader) :
    QWidget(parent),
    ui(new Ui::AddLabsGUI)
{
    grader = aGrader;
    ui->setupUi(this);
    done = false;
}

/**
 * @brief AddLabsGUI::~AddLabsGUI
 * deconstructs AddLabsGUI
 */
AddLabsGUI::~AddLabsGUI(){
    delete ui;
}

/**
 * @brief AddLabsGUI::on_selectButton_clicked
 * passes file path to fileparser in grader to iterate through subdirectories and
 * parse lab submissions
 */
void AddLabsGUI::on_selectButton_clicked(){
    //save file path
    string filepath = ui->labPathText->toPlainText().toStdString();
    labIDList = grader->get_file_parser()->parse_java_file(filepath);
    done = true;
    delete this;
}

/**
 * @brief AddLabsGUI::on_browseButton_clicked
 * Opens file dialog to allow users to browse for a file path to a directory of lab submissions
 */
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

bool AddLabsGUI::get_done()
{
    return this->done;
}

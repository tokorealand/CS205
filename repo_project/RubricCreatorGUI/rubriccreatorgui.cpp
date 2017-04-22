#include "rubriccreatorgui.h"
#include "ui_rubriccreatorgui.h"

RubricCreatorGUI::RubricCreatorGUI(QWidget *parent, Grader* grader) :
    QWidget(parent),
    ui(new Ui::RubricCreatorGUI)
{
    ui->setupUi(this);
    this->grader = grader;
}

RubricCreatorGUI::~RubricCreatorGUI(){
    delete ui;
}

void RubricCreatorGUI::display_sections(){

    ui->rubricSectionList->clear();
    ui->rubricSectionList->addItems(sections);

    ui->pointValueList->clear();
    ui->pointValueList->addItems(pointVals);

    ui->colorList->clear();
    ui->colorList->addItems(colors);

    ui->totalPoints->setText(QString("%1").arg(totalPoints));

}

//done button
void RubricCreatorGUI::on_doneButton_clicked(){
    //create a rubric object
    r = new RubricObject();

    //initialize rubric object
    //sections - contains all the rubric sections
    for(int i = 0; i < ui->rubricSectionList->count(); i++){
        r->set_rubric_sections(ui->rubricSectionList->item(i)->text().toStdString());
    }
    //pointValues - contains all the point values
    for(int i = 0 ; i < ui->pointValueList->count(); i++){
        r->set_point_totals(ui->pointValueList->item(i)->text().toStdString());
    }
    //colors - contains all the colors
    for(int i = 0 ; i < ui->colorList->count(); i++){
        r->set_section_colors(ui->colorList->item(i)->text().toStdString());
    }
    //totalPoints - the total points in the rubric
    r->set_total_points(to_string(totalPoints));

    //add the temp rubric to grader
    grader->add_temp_rubric(r);

    close();//exit gui
}

//remove selected
void RubricCreatorGUI::on_removeSelectedButton_clicked(){

    //is a section selected
    if(ui->rubricSectionList->selectedItems().size()>0){\

        //get the location of the selected item in the list
        int a = ui->rubricSectionList->currentRow();
        string s = pointVals.at(a).toStdString();

        //remove the items at the location in each list
        sections.removeAt(a);
        pointVals.removeAt(a);
        colors.removeAt(a);

        int d = stoi(s);
        totalPoints = totalPoints - d;
    }

    //is point val selected
    if(ui->pointValueList->selectedItems().size()>0){
        //get the location of the selected item in the list
        int a = ui->pointValueList->currentRow();
        string s = pointVals.at(a).toStdString() + "";

        //remove the items at the location in each list
        sections.removeAt(a);
        pointVals.removeAt(a);
        colors.removeAt(a);

        int d = stoi(s);
        totalPoints = totalPoints - d;
    }

    //is color selected
    if(ui->colorList->selectedItems().size()>0){
        //get the location of the selected item in the list
        int a = ui->colorList->currentRow();
        string s = pointVals.at(a).toStdString() + "";

        //remove the items at the location in each list
        sections.removeAt(a);
        pointVals.removeAt(a);
        colors.removeAt(a);

        int d = stoi(s);
        totalPoints = totalPoints - d;
    }

    //update the display
    display_sections();
}

void RubricCreatorGUI::on_addSectionButton_clicked(){

    //add the rubric section
    QString newSection = ui->addRubricSectionText->toPlainText();
    sections.append(newSection);

    //add the point values
    QString newPointVal = ui->pointValueSpinBox->cleanText();
    pointVals.append(newPointVal);

    //add the colors
    QString newColor = ui->colorDropDown->currentText();
    colors.append(newColor);

    totalPoints = totalPoints + ui->pointValueSpinBox->value();

    display_sections();
}

RubricObject* RubricCreatorGUI::get_rubric(){
    return r;
}







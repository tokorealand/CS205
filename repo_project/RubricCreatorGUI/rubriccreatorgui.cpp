#include "rubriccreatorgui.h"
#include "ui_rubriccreatorgui.h"

RubricCreatorGUI::RubricCreatorGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RubricCreatorGUI)
{
    ui->setupUi(this);
}

RubricCreatorGUI::~RubricCreatorGUI()
{
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


    //sections - contains all the rubric sections
    //pointValues - contains all the point values
    //colors - contains all the colors
    //totalPoints - the total points in the rubric

    close();//exit gui

}

//remove selected
void RubricCreatorGUI::on_removeSelectedButton_clicked(){

    if(ui->rubricSectionList->selectedItems().size()>0){
        sections.removeOne(ui->rubricSectionList->selectedItems().at(0)->text());
    }
    if(ui->pointValueList->selectedItems().size()>0){
        pointVals.removeOne(ui->pointValueList->selectedItems().at(0)->text());

        string s = ui->pointValueList->selectedItems().at(0)->text().toStdString(); //.toStdString().constData();
        double d = stod(s);
        totalPoints = totalPoints - d;
    }
    if(ui->colorList->selectedItems().size()>0){
        colors.removeOne(ui->colorList->selectedItems().at(0)->text());
    }

    display_sections();
}

void RubricCreatorGUI::on_addSectionButton_clicked()
{

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

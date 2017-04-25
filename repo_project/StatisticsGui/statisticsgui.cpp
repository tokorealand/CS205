#include "statisticsgui.h"
#include "ui_statisticsgui.h"

StatisticsGui::StatisticsGui(QWidget *parent, Grader *grad) :
    QWidget(parent),
    ui(new Ui::StatisticsGui)
{
    ui->setupUi(this);
    this->grad = grad;
    display_years();
}

StatisticsGui::~StatisticsGui(){
    delete ui;
}

void StatisticsGui::display_years(){

    QList<QString> ycontainer;

    ui->yearSelect->clear();

    if(grad->get_years().size()>0){
        std::vector<Year*> holder = grad->get_years();

        for(Year* it: holder){
            ycontainer.append(QString::fromStdString(it->get_id()));
        }
        ui->yearSelect->addItems(ycontainer);
    }
}

void StatisticsGui::on_yearSelect_activated(const QString &arg1){

    selected_year = grad->get_year(arg1.QString::toStdString());

    QList<QString> semcontainer;

    ui->semesterSelect->clear();
    ui->classSelect->clear();

    std::vector<Semester*> holder = selected_year->get_semesters();

    for(Semester* it: holder){
        semcontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->semesterSelect->addItems(semcontainer);
}

void StatisticsGui::on_semesterSelect_activated(const QString &arg1){

    string semesterID = arg1.toStdString()+"_"+selected_year->get_id();
    selected_semester=grad->get_semester(semesterID);

    QList<QString> ccontainer;
    ui->classSelect->clear();

   std::vector<Class*> holder = selected_semester->get_classes();

    for(Class* it: holder){
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->classSelect->addItems(ccontainer);
}

void StatisticsGui::on_classSelect_activated(const QString &arg1){

    string classID = arg1.toStdString()+"_"+selected_semester->get_id();

    selected_class=grad->get_class(classID);

    QList<QString> ccontainer;
    ui->sectionSelect->clear();

   std::vector<Section*> holder = selected_class->get_sections();

    for(Section* it: holder){
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->sectionSelect->addItems(ccontainer);
}
void StatisticsGui::on_sectionSelect_activated(const QString &arg1){

    string sectionID = arg1.toStdString()+"_"+selected_class->get_id();

    selected_section=grad->get_section(sectionID);

    QList<QString> ccontainer;
    ui->labNoSelect->clear();

   // std::vector<Labs*> holder = selected_section->get_students().at(0).get_labs();


    //ui->labNoSelect->addItems(ccontainer);
}

void StatisticsGui::on_calcbutton_clicked(){
}

void StatisticsGui::on_doneButton_clicked()
{
close();
}

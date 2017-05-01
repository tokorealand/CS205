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

    selected_section = grad->get_section(sectionID);

    QList<QString> ccontainer;
    ui->labNoSelect->clear();

    std::vector<Lab*> holder = selected_section->get_students().at(0)->get_labs();

    for(Lab* it: holder){
        ccontainer.append(QString::fromStdString(it->get_lab_num()));
    }

    ui->labNoSelect->addItems(ccontainer);
}

void StatisticsGui::on_labSelect_activated(const QString &arg1){

    string labID = arg1.toStdString()+"_"+selected_section->get_id();

    selected_lab = grad->get_lab(labID);
}

void StatisticsGui::on_calcbutton_clicked(){

    //display calculated min
    ui->mindisplay->setText(QString::fromStdString(calc_min()));

    //display calculated max
    ui->maxdisplay->setText(QString::fromStdString(calc_max()));

    //display calculated median
    ui->mediandisplay->setText(QString::fromStdString(calc_median()));

    //display calculated mean
    ui->meandisplay->setText(QString::fromStdString(calc_mean()));
}

void StatisticsGui::on_doneButton_clicked(){
    close();
}

string StatisticsGui::calc_min(){

    //get all of the students
    vector<Student*> students = selected_section->get_students();

    //get a temp min
    int currentMin = 100;

    //search through all the student labs
    for (int i = 0; i < students.size(); i++){

        Student* tempStu = students.at(i); //get a temp student and their labs

        vector<Lab*> labs = tempStu->get_labs(); //get all that student's labs

        Lab *currentLab = labs.at(0); //get the current lab

        //reset min?
        if(currentLab->get_grade() < currentMin){
            currentMin = currentLab->get_grade(); //reset min
        }
    }

    return to_string(currentMin);
}

string StatisticsGui::calc_max(){

    //get all of the students
    vector<Student*> students = selected_section->get_students();

    //get a temp min
    int currentMax = 0;

    //search through all the student labs
    for (int i = 0; i < students.size(); i++){

        Student* tempStu = students.at(i); //get a temp student and their labs

        vector<Lab*> labs = tempStu->get_labs(); //get all that student's labs

        Lab *currentLab = labs.at(0); //get the current lab

        //reset min?
        if(currentLab->get_grade() > currentMax){
            currentMax = currentLab->get_grade(); //reset min
        }
    }
    return to_string(currentMax);
}

string StatisticsGui::calc_median(){
    //get all of the students
    vector<Student*> students = selected_section->get_students();

    vector<int> keepGrades;

    //collect all the grades
    for (int i = 0; i < students.size(); i++){

        Student* tempStu = students.at(i); //get a temp student and their labs

        vector<Lab*> labs = tempStu->get_labs(); //get all that student's labs

        Lab *currentLab = labs.at(0); //get the current lab

        keepGrades.push_back(currentLab->get_grade());
    }

    //sort the grades high to low
    std::sort(keepGrades.begin(), keepGrades.end());

    return to_string(keepGrades.at(keepGrades.size()/2));
}

string StatisticsGui::calc_mean(){

    //get all of the students
    vector<Student*> students = selected_section->get_students();

    //get a temp min
    int total = 0;

    //create a vector of students
    vector<Lab*> labs;

    //search through all the student labs
    for (int i = 0; i < students.size(); i++){

        Student* tempStu = students.at(i); //get a temp student and their labs

        labs.push_back(tempStu->get_labs().at(0));
    }

    for (int i = 0; i < labs.size(); i ++){
        total += labs.at(i)->get_grade();
    }

    return to_string(total/students.size());
}

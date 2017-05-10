#include "statisticsgui.h"
#include "ui_statisticsgui.h"

/*!
  @class Statistics gui
  @brief This class sets up and builds a statistics gui. It calculates and displays
  four statistics (min, max, median, and mean) for the selected lab.
 */

/**
 * @brief StatisticsGui::StatisticsGui constructor.
 * @param parent
 * @param grad
 *
 * sets the class's grader to grad and sets up the ui.
 */
StatisticsGui::StatisticsGui(QWidget *parent, Grader *grad) :
    QWidget(parent),
    ui(new Ui::StatisticsGui)
{
    ui->setupUi(this);
    this->grad = grad;
    display_years();
}

/*!
 * \brief StatisticsGui::~StatisticsGui
 *
 * the deconstructor.
 */
StatisticsGui::~StatisticsGui(){
    delete ui;
}

/**
 * @brief StatisticsGui::display_years
 *
 * when the program begins, it displays the years of the labs that are in the
 * grader in a drop down list in the ui.
 */
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

/**
 * @brief StatisticsGui::on_yearSelect_activated
 * @param arg1
 *
 * a slot that is activated when the user selects a year from the year drop down
 * in the ui. It then populates the semester drop down with the semesters
 * associated with the selected year, based on what is held in the grader.
 */
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

/**
 * @brief StatisticsGui::on_semesterSelect_activated
 * @param arg1
 *
 * a slot that is activated when the user selects a semester from the drop
 * down in the ui. It then populates the class drop down with the classes
 * associated with the selected semester, based on what is held in grader.
 */
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

/**
 * @brief StatisticsGui::on_classSelect_activated
 * @param arg1
 *
 * a slot that is activated when the user selects a class from the drop down
 * in the ui. It then populates the section drop down with the sections
 * associated with the selected class, based on what is held in grader.
 */
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

/**
 * @brief StatisticsGui::on_sectionSelect_activated
 * @param arg1
 *
 * a slot that is activated when the user selects a section from the drop down
 * in the ui. It then populates the lab number drop down with the lab numbers
 * associated with the selected section, based on what is held in grader.
 */
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

/**
 * @brief StatisticsGui::on_labSelect_activated
 * @param arg1
 *
 * a slot that is activated when the user selects a lab num from the drop down
 * in the ui. When the user selects a lab, it will save that lab as the current
 * selected lab.
 */
void StatisticsGui::on_labSelect_activated(const QString &arg1){

    string labID = arg1.toStdString()+"_"+selected_section->get_id();

    selected_lab = grad->get_lab(labID);
}

/**
 * @brief StatisticsGui::on_calcbutton_clicked
 *
 * a slot for when the calc button is clicked in the ui. calls methods that
 * calculate statistics and displays them in the ui.
 */
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

/**
 * @brief StatisticsGui::on_doneButton_clicked
 *
 * closes the ui.
 */
void StatisticsGui::on_doneButton_clicked(){
    close();
}

/**
 * @brief StatisticsGui::calc_min
 * @return the minimum score for all the selected labs
 *
 * loops through all selected labs and finds the lowest grade.
 */
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

/**
 * @brief StatisticsGui::calc_max
 * @return the maximum score for all the selected labs
 *
 * loops through all the selected labs and finds the maximum
 */
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

/**
 * @brief StatisticsGui::calc_median
 * @return the median score of all the selected labs
 *
 * calculates the median grade from all the currently selected labs
 */
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

/**
 * @brief StatisticsGui::calc_mean
 * @return the mean score of all the selected labs
 *
 * calculates the mean grade of all the currently selected labs
 */
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

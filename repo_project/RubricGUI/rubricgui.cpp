#include "rubricgui.h"
#include "ui_rubricgui.h"

RubricGUI::RubricGUI(QWidget *parent, Grader* aGrader) :
    QWidget(parent),
    ui(new Ui::RubricGUI)
{
    ui->setupUi(this);
    this->grad = aGrader;
    display_years();
}

RubricGUI::~RubricGUI()
{
    delete ui;
}

void RubricGUI::on_yearSelect_activated(const QString &arg1)
{
    selected_year = grad->get_year(arg1.QString::toStdString());
    QList<QString> semcontainer;
    ui->semesterSelect->clear();
    ui->classSelect->clear();

    std::vector<Semester*> holder = selected_year->get_semesters();

    for(Semester* it: holder)
    {
        semcontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->semesterSelect->addItems(semcontainer);
}

void RubricGUI:: display_years()
{
    QList<QString> ycontainer;
    ui->yearSelect->clear();

    if(grad->get_years().size()>0)
    {
        std::vector<Year*> holder = grad->get_years();

        for(Year* it: holder)
        {
            ycontainer.append(QString::fromStdString(it->get_id()));
        }

        ui->yearSelect->addItems(ycontainer);
    }
}



void RubricGUI::on_semesterSelect_activated(const QString &arg1)
{
    string semesterID = arg1.toStdString()+"_"+selected_year->get_id();
    selected_semester=grad->get_semester(semesterID);

    QList<QString> ccontainer;
    ui->classSelect->clear();

   std::vector<Class*> holder = selected_semester->get_classes();

    for(Class* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->classSelect->addItems(ccontainer);
}

void RubricGUI::on_classSelect_activated(const QString &arg1)
{
    string classID = arg1.toStdString()+"_"+selected_semester->get_id();

    selected_class=grad->get_class(classID);
}



void RubricGUI::on_createRubric_clicked()
{
    if(selected_class != nullptr)
    {
        string rubricID = to_string( ui->selectLab->value()) + "_" + selected_class->get_id();
        grad->add_rubric(rubricID, selected_class->get_id());
        selected_rubric = grad->get_rubric(rubricID);
    }
}



void RubricGUI::on_addSection_clicked()
{
    if(selected_rubric !=nullptr)
    {
        string rubricsectionID ="_" + selected_rubric->get_id();
        string description;
        string color;
        string points;
        //grad->add_rubricsection(rubricsectionID, selected_rubric->get_id(),);
    }
}

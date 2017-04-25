#include "rubricgui.h"
#include "ui_rubricgui.h"

RubricGUI::RubricGUI(QWidget *parent, Grader* aGrader) :
    QWidget(parent),
    ui(new Ui::RubricGUI)
{
    ui->setupUi(this);
    this->grad = aGrader;
    display_years();
    display_colors();
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
    ui->rubricSelect->clear();

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
    ui->rubricSelect->clear();

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

    selected_class = grad->get_class(classID);

    QList<QString> ccontainer;
    ui->rubricSelect->clear();

    std::vector<RubricObject*> holder = selected_class->get_rubrics();

    for(RubricObject* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->rubricSelect->addItems(ccontainer);
}



void RubricGUI::on_createRubric_clicked()
{
    if(selected_class != nullptr)
    {
        string rubricID = to_string( ui->selectLab->value()) + "_" + selected_class->get_id();
        grad->add_rubric(rubricID, selected_class->get_id());
        ui->rubricSelect->addItem(QString::fromStdString("Rubric_"+to_string( ui->selectLab->value())));
    }
}



void RubricGUI::on_addSection_clicked()
{
    if(selected_rubric !=nullptr)
    {
        string rubricsectionID =to_string(selected_rubric->get_rubric_sections().size())+"_" + selected_rubric->get_id();
        string description = ui->selectDescription->toPlainText().toStdString();
        string color = ui->selectColor->currentText().toStdString();
        string points = to_string(ui->selectPoints->value());
        ui->rubricsectionSelect->addItem(QString::fromStdString(points+" | "+color+" | "+description));
        grad->add_rubricsection(rubricsectionID, selected_rubric->get_id(), description, points, color);
    }
}

void RubricGUI::display_colors(){
    QList<QString> container;
    ui->selectColor->clear();
    container.append("red");
    container.append("green");
    container.append("blue");
    container.append("cyan");
    container.append("magenta");
    container.append("yellow");
    ui->selectColor->addItems(container);
}


void RubricGUI::on_rubricSelect_activated(const QModelIndex &index){
    string r = ui->rubricSelect->currentItem()->text().toStdString();
    string rubricID = r.substr(r.find("_")+1, r.length())+"_"+selected_class->get_id();
    selected_rubric = grad->get_rubric(rubricID);

    QList<QString> ccontainer;
    ui->rubricsectionSelect->clear();

    std::vector<RubricSection*> holder = selected_rubric->get_rubric_sections();

    for(RubricSection* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_points()+" | "+it->get_color()+" | "+it->get_description()));
    }
    ui->rubricsectionSelect->addItems(ccontainer);
}

void RubricGUI::on_rubricsectionSelect_activated(const QModelIndex &index){

}

void RubricGUI::on_deleteRubric_clicked()
{
    selected_rubric->set_deleted();
    for(int i = 0; i , selected_rubric->get_rubric_sections().size(); i++)
    {
        selected_rubric->get_rubric_sections().at(i)->set_deleted();
        delete selected_rubric->get_rubric_sections().at(i);
    }
    delete selected_rubric;
}

void RubricGUI::on_removeSection_clicked()
{
    selected_rubric_section->set_deleted();
    delete selected_rubric_section;
}

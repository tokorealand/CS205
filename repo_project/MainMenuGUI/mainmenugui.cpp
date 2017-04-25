#include "mainmenugui.h"
#include "ui_mainmenugui.h"

MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    anonymous_grading = false;
    ui->setupUi(this);
    grad = new Grader();
    display_years();
}

MainMenuGUI::~MainMenuGUI()
{
    delete ui;
    delete grad;
}

void MainMenuGUI::display_years()
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

void MainMenuGUI::on_yearSelect_activated(const QString &arg1)
{
    selected_year = grad->get_year(arg1.QString::toStdString());
    QList<QString> semcontainer;
    ui->semesterSelect->clear();
    ui->classSelect->clear();
    ui->sectionSelect->clear();
    ui->studentSelect->clear();
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();

    std::vector<Semester*> holder = selected_year->get_semesters();

    for(Semester* it: holder)
    {
        semcontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->semesterSelect->addItems(semcontainer);
}

void MainMenuGUI::on_actionAdd_New_Labs_triggered()
{
    AddLabsGUI* alg = new AddLabsGUI(0, grad);
    alg->show();
}

void MainMenuGUI::on_actionExport_Lab_triggered(){
    int rubricIndex = stoi(selected_lab->get_lab_num())-1;
    x.combine_lab(selected_lab, selected_class, rubricIndex);

}

void MainMenuGUI::on_Refresh_clicked(){
    display_years();
}

void MainMenuGUI::on_semesterSelect_activated(const QString &arg1)
{
    string semesterID = arg1.toStdString()+"_"+selected_year->get_id();
    selected_semester=grad->get_semester(semesterID);


    QList<QString> ccontainer;
    ui->classSelect->clear();
    ui->sectionSelect->clear();
    ui->studentSelect->clear();
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();

   std::vector<Class*> holder = selected_semester->get_classes();

    for(Class* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->classSelect->addItems(ccontainer);
}



void MainMenuGUI::on_classSelect_activated(const QString &arg1)
{
    string classID = arg1.toStdString()+"_"+selected_semester->get_id();

    selected_class=grad->get_class(classID);


    QList<QString> ccontainer;
    ui->sectionSelect->clear();
    ui->studentSelect->clear();
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();

   std::vector<Section*> holder = selected_class->get_sections();

    for(Section* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->sectionSelect->addItems(ccontainer);
}


void MainMenuGUI::on_sectionSelect_activated(const QString &arg1)
{

    string sectionID = arg1.toStdString() +"_"+selected_class->get_id();

    selected_section=grad->get_section(sectionID);

    QList<QString> ccontainer;
    ui->studentSelect->clear();
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();

   std::vector<Student*> holder = selected_section->get_students();

    int i = 0;

    for(Student* it: holder)
    {
        if(anonymous_grading == false)
        {
        ccontainer.append(QString::fromStdString(it->get_first_name()+"_"+it->get_last_name()));
        }
        else
        {
            ccontainer.append(QString::fromStdString("Student_" + to_string(i)));
        }

       i++;
    }

    ui->studentSelect->addItems(ccontainer);
}



void MainMenuGUI::on_studentSelect_activated(const QString &arg1)
{

    if(anonymous_grading == false)
    {
     string studentID = arg1.toStdString() +"_"+selected_section->get_id();
     selected_student = grad->get_student(studentID);
    }
    else
    {
        string student = arg1.toStdString();
      int studentIndex = atoi(student.substr(student.find("_"), student.length() -1).c_str());
      selected_student = selected_section->get_students().at(studentIndex);
    }

    QList<QString> ccontainer;
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();

   std::vector<Lab*> holder = selected_student->get_labs();

    for(Lab* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_lab_num()));
    }

    ui->labSelect->addItems(ccontainer);
}


void MainMenuGUI::on_labSelect_activated(const QString &arg1)
{
    string labID = arg1.toStdString() +"_"+selected_student->get_id();

    selected_lab=grad->get_lab(labID);

    QList<QString> ccontainer;
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->displayLabGrade->clear();
    ui->displayLabGrade->setText(QString::fromStdString(to_string(selected_lab->get_grade())));
    ui->disrubric->clear();
    display_rubric_text();


   std::vector<Component*> holder = selected_lab->get_components();

    for(Component* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_name()));
    }

    ui->componentSelect->addItems(ccontainer);
}



void MainMenuGUI::on_componentSelect_activated(const QModelIndex &index)
{
    string componentID = ui->componentSelect->currentItem()->text().toStdString()+"_"+selected_lab->get_id();

    selected_component=grad->get_component(componentID);


    QList<QString> ccontainer;
    ui->disjava->clear();
    ui->discomment->clear();
    display_component_text();

   std::vector<Comment*> holder = selected_component->get_comments();

    for(Comment* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_comment_text()));
    }

    ui->discomment->addItems(ccontainer);
}



void MainMenuGUI::display_component_text()
{
    QList<QString> jtcontainer;

    if(selected_component != NULL)
    {

        for(int i = 0; i<selected_component->get_text_lines().size(); i++)
        {
            string  javaText = to_string(i) + "     " +selected_component->get_text_lines().at(i);
            jtcontainer.push_back(QString::fromStdString(javaText));
        }

        ui->disjava->addItems(jtcontainer);
    }
    else
    {
        ui->disjava->clear();
        QString nolab = "PLEASE SELECT LAB";
        ui->disjava->addItem(nolab);
    }
}


void MainMenuGUI::display_comment_text()
{
    ui->discomment->clear();
    QList<QString> jtcontainer;
    for(int i = 0; i<selected_component->get_comments().size(); i++)
    {
        string  commentText = selected_component->get_comments().at(i)->get_comment_text();
        jtcontainer.push_back(QString::fromStdString(commentText));
    }
    ui->discomment->addItems(jtcontainer);
}


void MainMenuGUI::display_rubric_text()
{
    ui->disrubric->clear();

    int num = std::atoi(selected_lab->get_lab_num().c_str());
    if(selected_class->get_rubrics().size() >= std::atoi(selected_lab->get_lab_num().c_str()))
    {
        RubricObject* current = selected_class->get_rubrics().at(std::atoi(selected_lab->get_lab_num().c_str()) - 1);

        QList<QString> container;

        for(int i = 0; i < current->get_rubric_sections().size(); i++)
        {
           string rubricSectionPoints = current->get_rubric_sections().at(i)->get_points();
           string rubricSectionColor = current->get_rubric_sections().at(i)->get_color();
           string rubricSectionDescription = current->get_rubric_sections().at(i)->get_description();
           container.append(QString::fromStdString(rubricSectionPoints+"|"+rubricSectionColor+"|"+rubricSectionDescription));
        }
        ui->disrubric->addItems(container);
    }
    else
    {
        ui->disrubric->addItem("No rubric to display. File -> Add Rubric to add a rubric for the specified lab");
    }

}


void MainMenuGUI::on_saveAndExit_clicked()
{
    this->close();
}

void MainMenuGUI::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        anonymous_grading = true;
    }
    else
    {
         anonymous_grading = false;
    }

    ui->studentSelect->clear();
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();
}

void MainMenuGUI::on_actionComment_triggered()
{
    if(selected_component != nullptr){ // only open the comment engine if there is a lab
//        cout<< grad <<endl;
//        cout << selected_lab << endl;
        Dialog *c = new Dialog(0, grad, selected_lab, selected_component);
        c->show();
    }
}

void MainMenuGUI::on_actionAdd_Rubric_triggered()
{
    RubricGUI* rg = new RubricGUI(0, grad);
    rg->show();
}

void MainMenuGUI::on_actionCalculate_Stats_triggered(){
    StatisticsGui* sg = new StatisticsGui(0, grad);
    sg->show();
}

void MainMenuGUI::on_deleteComment_clicked()
{
    Comment* selected_comment = selected_component->get_comments().at(ui->discomment->currentRow());
    selected_comment->set_deleted();
    delete selected_comment;
}

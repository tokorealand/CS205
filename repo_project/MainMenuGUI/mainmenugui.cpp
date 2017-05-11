#include "mainmenugui.h"
#include "ui_mainmenugui.h"

/**
 * @brief MainMenuGUI::MainMenuGUI, All acts as the main menu for the project.
 * Keeps track of current year, semster, class, section, student, lab, component, rubric,
 * and comment that are being used. Displays selected students lab and calls all other guis.
 * @param parent
 *
 */
MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    anonymous_grading = false;
    ui->setupUi(this);
    grad = new Grader();
    display_years();
    ui->progressBar->setValue(0);
}

/**
 * @brief MainMenuGUI::~MainMenuGUI, Deletes grader, cascading down the class skeleton
 */
MainMenuGUI::~MainMenuGUI()
{
    delete ui;
    delete grad;
}

/**
 * @brief MainMenuGUI::display_years, Displays years that have been input to the project.
 * Clears all other selections when called.
 */
void MainMenuGUI::display_years()
{
    QList<QString> ycontainer;
    ui->yearSelect->clear();
    ui->semesterSelect->clear();
    ui->classSelect->clear();
    ui->sectionSelect->clear();
    ui->studentSelect->clear();
    ui->labSelect->clear();
    ui->componentSelect->clear();
    ui->disjava->clear();
    ui->discomment->clear();
    ui->disrubric->clear();

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

/**
 * @brief MainMenuGUI::on_yearSelect_activated, When activated uses arg 1 to find selected year in database
 * @param arg1, used as ID for year in database
 */
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

/**
 * @brief MainMenuGUI::on_actionAdd_New_Labs_triggered,
 * When triggered calls add new lab gui, waits for input and then automatically refreshes by calling display_years()
 */
void MainMenuGUI::on_actionAdd_New_Labs_triggered()
{
    AddLabsGUI* alg = new AddLabsGUI(0, grad);
    alg->show();

    while(alg->get_done() == false)
    {
       QApplication::processEvents();
    }

    display_years();

}

/**
 * @brief MainMenuGUI::on_actionExport_Lab_triggered
 * Exports selected lab in html format when triggered
 */
void MainMenuGUI::on_actionExport_Lab_triggered(){
    if(selected_lab!=nullptr && selected_lab->get_graded()=="1")
    {
    int rubricIndex = stoi(selected_lab->get_lab_num())-1;
    x.combine_lab(selected_lab, selected_class, rubricIndex);
    }

}


/**
 * @brief MainMenuGUI::on_semesterSelect_activated
 * When activated uses arg 1 to find selected semseter in database
 * @param arg1, used as ID for semester in database
 */
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


/**
 * @brief MainMenuGUI::on_classSelect_activated
 * When activated uses arg 1 to find selected class in database
 * @param arg1, used as ID to find class in database
 */
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

/**
 * @brief MainMenuGUI::on_sectionSelect_activated
 * When activated uses arg 1 to find selected section in database
 * @param arg1, used as ID to find section in database
 */
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


/**
 * @brief MainMenuGUI::on_studentSelect_activated
 * When activated uses arg 1 to find selected student in database
 * @param arg1, used as ID to find student in database
 */
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
      int studentIndex = atoi(student.substr(student.find("_")+1, student.length()).c_str());
      selected_student = selected_section->get_students().at(studentIndex);
      string name = selected_student->get_first_name();
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

/**
 * @brief MainMenuGUI::on_labSelect_activated
 * When activated uses arg 1 to find selected lab in database
 * @param arg1, used as ID to find lab in database
 */
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

    if(selected_lab->get_graded()=="1")
    {
    ui->checkBox_2->setChecked(true);
    }
    else{
        ui->checkBox_2->setChecked(false);

    }

    ui->progressBar->setValue(selected_class->get_amount_graded(selected_lab->get_lab_num()));
}


/**
 * @brief MainMenuGUI::on_componentSelect_activated
 * When activated uses arg 1 to find selected component in database
 * @param index, used as ID to find component in database
 */
void MainMenuGUI::on_componentSelect_activated(const QModelIndex &index)
{
    string componentID = ui->componentSelect->currentItem()->text().toStdString()+"_"+selected_lab->get_id();

    selected_component=grad->get_component(componentID);

    QList<QString> ccontainer;
    ui->disjava->clear();
    ui->discomment->clear();
    display_component_text();
    display_comment_text();
}


/**
 * @brief MainMenuGUI::display_component_text
 */
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

/**
 * @brief MainMenuGUI::display_comment_text
 * Diplays all comments of the selected component.
 * Shows points off, text, and section relating to a comment.
 */
void MainMenuGUI::display_comment_text()
{
    ui->discomment->clear();
    QList<QString> jtcontainer;
    for(int i = 0; i<selected_component->get_comments().size(); i++)
    {
         string  commentText = "";
        if(selected_component->get_comments().at(i)->get_deleted() == false)
        {
            commentText = "-"+to_string(selected_component->get_comments().at(i)->get_points())
                                     +" | "+selected_component->get_comments().at(i)->get_rubric_section()
                                     +" | " +selected_component->get_comments().at(i)->get_comment_text();

        }
        jtcontainer.push_back(QString::fromStdString(commentText));
    }
    ui->discomment->addItems(jtcontainer);
}


/**
 * @brief MainMenuGUI::display_rubric_text
 * Displays rubric of a labnumber in a selected class.
 * Both lab and class must be selected before rubric is displayed
 */
void MainMenuGUI::display_rubric_text()
{
    ui->disrubric->clear();
    if(selected_lab != nullptr)
    {
        int num = std::atoi(selected_lab->get_lab_num().c_str());

        if(selected_class->get_rubrics().size() >= std::atoi(selected_lab->get_lab_num().c_str()))
        {
            RubricObject* current = selected_class->get_rubrics().at(std::atoi(selected_lab->get_lab_num().c_str()) - 1);

            if(current->get_deleted() == false)
            {

                QList<QString> container;

                for(int i = 0; i < current->get_rubric_sections().size(); i++)
                {
                    QString output = "";
                    if(current->get_rubric_sections().at(i)->get_deleted() == false)
                    {
                       string rubricSectionPoints = current->get_rubric_sections().at(i)->get_points();
                       string rubricSectionColor = current->get_rubric_sections().at(i)->get_color();
                       string rubricSectionDescription = current->get_rubric_sections().at(i)->get_description();
                       output = QString::fromStdString(rubricSectionPoints+"|"+rubricSectionColor+"|"+rubricSectionDescription);
                       container.append(output);
                    }
                }
                ui->disrubric->addItems(container);
            }
        }
        else
        {
            ui->disrubric->addItem("No rubric to display. File -> Add Rubric to add a rubric for the specified lab");
        }
    }

}

/**
 * @brief MainMenuGUI::on_saveAndExit_clicked
 * Closes main menu gui, triggering cascading deconstructors in class skeleton
 * and saving that information to the database
 */
void MainMenuGUI::on_saveAndExit_clicked()
{
    this->close();
}

/**
 * @brief MainMenuGUI::on_checkBox_toggled
 * Toggles anonymous grading by masking student ID to user
 * @param checked
 * Anonymous grading on when checked
 */
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

/**
 * @brief MainMenuGUI::on_actionComment_triggered
 * When triggered calls the comment gui, must have a rubric created for
 * that class/ lab number and selected component to function.
 * Waits for input then automatically refreshes comment/grade display
 */
void MainMenuGUI::on_actionComment_triggered()
{
    if(selected_component != nullptr && selected_class->get_rubrics().size() <= atoi(selected_lab->get_lab_num().c_str()))
    { // only open the comment engine if there is a lab

        Dialog *c = new Dialog(0, grad, selected_lab, selected_component, selected_class);
        c->show();

        while(c->get_done() == false)
        {
           QApplication::processEvents();
        }

        display_comment_text();
        ui->displayLabGrade->clear();
        ui->displayLabGrade->setText(QString::fromStdString(to_string(selected_lab->get_grade())));

    }
}

/**
 * @brief MainMenuGUI::on_actionAdd_Rubric_triggered
 * When triggered calls the rubric gui. Waits for input then
 *  automatically refreshes rubric display
 */
void MainMenuGUI::on_actionAdd_Rubric_triggered()
{
    RubricGUI* rg = new RubricGUI(0, grad);
    rg->show();
    while(rg->get_done() == false)
    {
       QApplication::processEvents();
    }

    display_rubric_text();

}

/**
 * @brief MainMenuGUI::on_actionCalculate_Stats_triggered
 * When triggered, calls the statistics gui
 */
void MainMenuGUI::on_actionCalculate_Stats_triggered(){
    StatisticsGui* sg = new StatisticsGui(0, grad);
    sg->show();
}

/**
 * @brief MainMenuGUI::on_deleteComment_clicked
 * Deletes a comment from a component by setting a boolean 'deleted' to true.
 * Comments with 'deleted boolean set to true will not be displayed, counted
 *  towards lab grade, and will not be added to database upon deconstruction
 */
void MainMenuGUI::on_deleteComment_clicked()
{
    int check =ui->discomment->currentRow();
    if(selected_component != nullptr && check != -1)
    {
      selected_component->get_comments().at(ui->discomment->currentRow())->set_deleted();
      display_comment_text();
      ui->displayLabGrade->clear();
      ui->displayLabGrade->setText(QString::fromStdString(to_string(selected_lab->get_grade())));
    }
}


/**
 * @brief MainMenuGUI::on_checkBox_2_toggled
 * Toggles a lab as graded by setting a 'graded' boolean in lab to true,
 * updates progress bar whenever toggled
 * @param checked
 * checked indicates a graded lab, unchecked indicates an ungraded lab
 */
void MainMenuGUI::on_checkBox_2_toggled(bool checked)
{
    if(selected_lab!=NULL)
    {
        if(checked==true){
        selected_lab->set_graded("1");
        }
        else if(checked==false){
            selected_lab->set_graded("0");
        }
         ui->progressBar->setValue(selected_class->get_amount_graded(selected_lab->get_lab_num()));
    }
}

/**
 * @brief MainMenuGUI::on_pushButton_2_clicked
 * Increases font size of component display when clicked.
 * Must have a selected component to function
 */
void MainMenuGUI::on_pushButton_2_clicked()
{
    if(ui->disjava->count() !=0 )
    {
        QFont fnt;
        int size = ui->disjava->item(0)->font().pointSize();
        fnt.setPointSize(size+5);
        fnt.setFamily("Arial");

        for(int i=0; i<ui->disjava->count(); i++)
        {
        ui->disjava->item(i)->setFont(fnt);
        }
    }
}

/**
 * @brief MainMenuGUI::on_pushButton_clicked
 * Decreases font size of component display when clicked.
 * Must have a selected component to function.
 */
void MainMenuGUI::on_pushButton_clicked()
{
    if( ui->disjava->count() != 0)
    {
        QFont fnt;
        int size = ui->disjava->item(0)->font().pointSize();

        if((size-5)>5)
        {
            fnt.setPointSize(size-5);
            fnt.setFamily("Arial");

            for(int i=0; i<ui->disjava->count(); i++)
            {
            ui->disjava->item(i)->setFont(fnt);
            }

        }
    }
}

/**
 * @brief MainMenuGUI::on_actionExport_Labs_triggered
 * Exports all labs in selected class and lab number in html format
 */
void MainMenuGUI::on_actionExport_Labs_triggered()
{
if(selected_class->check_all_matching_key_graded(selected_lab->get_lab_num())==true)
{
    int rubricIndex = stoi(selected_lab->get_lab_num())-1;

    std::vector<Lab*> labs = selected_class->get_labs();

    for(Lab* it : labs)
    {
        if(it->get_lab_num() == selected_lab->get_lab_num())
        {
    x.combine_lab(it, selected_class, rubricIndex);
        }
    }
 }
}


/**
 * @brief MainMenuGUI::on_actionArchive_triggered
 * pushes database file to remote repository when triggered
 */
void MainMenuGUI::on_actionArchive_triggered()
{
    //system("cd ../../../../../repo_project \n git add . \n git commit -m \"archive\" \n git push");
}

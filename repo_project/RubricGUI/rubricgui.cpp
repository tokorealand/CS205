#include "rubricgui.h"
#include "ui_rubricgui.h"

RubricGUI::RubricGUI(QWidget *parent, Grader* aGrader) :
    QWidget(parent),
    ui(new Ui::RubricGUI)
{
    ui->setupUi(this);
    this->grad = aGrader;
    done = false;
    display_years();
    display_colors();
}

/**
 * @brief RubricGUI::~RubricGUI
 *
 * deconstructor for the rubric gui.
 */
RubricGUI::~RubricGUI(){
    delete ui;
}

/**
 * @brief RubricGUI::on_yearSelect_activated
 * @param arg1
 *
 * a slot that gets the selected year from the year drop down and then populates
 * the semester drop down with the corresponding sections from grader.
 */
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

/**
 * @brief RubricGUI::display_years
 *
 * Displays the all the years in the grader in the years drop down.
 */
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

/**
 * @brief RubricGUI::on_semesterSelect_activated
 * @param arg1
 *
 * a slot that gets the selected semester from the year drop down and then
 * populates the class drop down with the corresponding sections from grader.
 */
void RubricGUI::on_semesterSelect_activated(const QString &arg1){

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

/**
 * @brief RubricGUI::on_classSelect_activated
 * @param arg1
 *
 * a slot that gets the selected semester from the year drop down and then
 * populates the rubric text box with the name of the current rubrics in that
 * selected class.
 */
void RubricGUI::on_classSelect_activated(const QString &arg1){

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

/**
 * @brief RubricGUI::on_createRubric_clicked
 *
 * create the rubric and add it to grader.
 */
void RubricGUI::on_createRubric_clicked()
{
    if(selected_class != nullptr)
    {
        string rubricID = to_string(ui->selectLab->value()) + "_" + selected_class->get_id();
        grad->add_rubric(rubricID, selected_class->get_id());
        ui->rubricSelect->addItem(QString::fromStdString("Rubric_"+to_string( ui->selectLab->value())));
    }
}

/**
 * @brief RubricGUI::on_addSection_clicked
 *
 * add the inputted section information to the rubric.
 */
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

/**
 * @brief RubricGUI::display_colors
 *
 * adds colors to the select color drop down
 */
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

/**
 * @brief RubricGUI::on_rubricSelect_activated
 * @param index
 *
 * a slot that adds rubric items to the rubric section box.
 */
void RubricGUI::on_rubricSelect_activated(const QModelIndex &index){

    string r = ui->rubricSelect->currentItem()->text().toStdString();
    string rubricID = r.substr(r.find("_")+1, r.length())+"_"+selected_class->get_id();
    selected_rubric = grad->get_rubric(rubricID);

    QList<QString> ccontainer;
    ui->rubricsectionSelect->clear();

    std::vector<RubricSection*> holder = selected_rubric->get_rubric_sections();

    for(RubricSection* it: holder){
        ccontainer.append(QString::fromStdString(it->get_points()+" | "+it->get_color()+" | "+it->get_description()));
    }
    ui->rubricsectionSelect->addItems(ccontainer);
}

/**
 * @brief RubricGUI::on_rubricsectionSelect_activated
 * @param index
 *
 * a slot that sets the selected rubric section when it is clicked on in the ui.
 */
void RubricGUI::on_rubricsectionSelect_activated(const QModelIndex &index){
    selected_rubric_section = selected_rubric->get_rubric_sections().at( ui->rubricsectionSelect->currentRow());
}

/**
 * @brief RubricGUI::on_deleteRubric_clicked
 *
 * a slot that deletes the selected rubric.
 */
void RubricGUI::on_deleteRubric_clicked()
{
//    if(selected_rubric != nullptr)
//    {
//        selected_rubric->set_deleted();
//        for(int i = 0; i < selected_rubric->get_rubric_sections().size(); i++)
//        {
//            selected_rubric->get_rubric_sections().at(i)->set_deleted();
//        }
//    }
}

/**
 * @brief RubricGUI::on_removeSection_clicked
 *
 * a slot that deletes the selected rubric section.
 */
void RubricGUI::on_removeSection_clicked()
{
//    if(selected_rubric_section != nullptr)
//    {
//        selected_rubric_section->set_deleted();
//    }
}

/**
 * @brief RubricGUI::on_doneButton_clicked
 *
 * a slot that closes the program.
 */
void RubricGUI::on_doneButton_clicked()
{
    done = true;
    close();
}

bool RubricGUI::get_done()
{
    return done;
}

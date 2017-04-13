#include "selectiongui.h"
#include "ui_selectiongui.h"

selectiongui::selectiongui(QWidget *parent, Grader *aGrader) :
    QWidget(parent),
    ui(new Ui::selectiongui)
{
   grader = aGrader;
//    grader->add_class("CS150",0);
//    grader->add_class("CS202",0);
//    grader->add_class("CS303",0);

//    grader->add_section("CS1501","CS150");
//    grader->add_section("CS1502","CS150");
//    grader->add_section("CS1503","CS150");

//    grader->add_section("CS2021","CS202");

//    grader->add_section("CS2022","CS202");

//    grader->add_section("CS2023","CS202");

//    grader->add_student("luislopez","CS1501","Luis","Lopez");
//    grader->add_student("luisbonilla","CS1501","Luis","Bonilla");

//    grader->add_student("josebonilla","CS1501","Jose","Bonilla");

//   // grader->add_lab();

//    std::vector<vector<std::string>> g;

//    grader->add_lab("lb01","luislopez","Recursion","1",g);
//    grader->add_lab("lb02","luislopez","Trees","2",g);
//    grader->add_lab("lb03","luislopez","Arrays","3",g);
//    grader->add_lab("lb04","luislopez","Tsp","4",g);








    ui->setupUi(this);
    QList<QString> ccontainer;

    std::cout<<grader->get_classes().size();
    std::vector<Class*> holder = grader->get_classes();

    for(Class* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->classlist->addItems(ccontainer);



    //  ui->classlist->addItems(grader->);
}

selectiongui::~selectiongui()
{
    delete ui;
}

void selectiongui::on_cs_clicked()
{
    QList<QString> scontainer;
    ui->sectionlist->clear();
    ui->studenlist->clear();
    ui->lablist->clear();


    cclass=grader->get_class(ui->classlist->currentItem()->text().QString::toStdString());
    std::vector<Section*> holder = cclass->get_sections();

    for(Section* it: holder)
    {
        scontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->sectionlist->addItems(scontainer);
}

void selectiongui::on_ss_clicked()
{
    QList<QString> stcontainer;
    ui->studenlist->clear();
    ui->lablist->clear();


    csection=grader->get_section(ui->sectionlist->currentItem()->text().QString::toStdString());
    std::vector<Student*> holder = csection->get_students();

    for(Student* it: holder)
    {
        stcontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->studenlist->addItems(stcontainer);
}

void selectiongui::on_sts_clicked()
{
    QList<QString> lbcontainer;
    ui->lablist->clear();


    cstudent=grader->get_student(ui->studenlist->currentItem()->text().QString::toStdString());
    std::vector<Lab*> holder = cstudent->get_labs();

    for(Lab* it: holder)
    {
        lbcontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->lablist->addItems(lbcontainer);
}
bool selectiongui:: lab_selected()
{
    return labselect;
}

Lab* selectiongui:: select_lab()
{
    return clab;
}

void selectiongui::on_ls_clicked()
{
clab=grader->get_lab(ui->lablist->currentItem()->text().QString::toStdString());
    labselect = true;
}

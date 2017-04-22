#include "mainmenugui.h"
#include "ui_mainmenugui.h"

MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    ui->setupUi(this);
    grad = new Grader();
    display_years();
}

MainMenuGUI::~MainMenuGUI()
{
    delete ui;
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
    selected_year=grad->get_year(arg1.QString::toStdString());
    QList<QString> semcontainer;
    ui->semesterSelect->clear();
    ui->sectionSelect->clear();
    //ui->student->clear();
    ui->labSelect->clear();

    std::vector<Semester*> holder = selected_year->get_semesters();

    for(Semester* it: holder)
    {
        semcontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->semesterSelect->addItems(semcontainer);
}

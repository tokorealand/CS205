#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

class Lab;
class RubricObject;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grad = new Grader();
//    grad->add_year("2017");
//    grad->add_semester("spring2017","2017");
//    grad->add_class("CS150spring2017","spring2017");
//    grad->add_section("cadad","CS150spring2017");
//    grad->add_student("luis_lopez","cadad","luis","lopez");
    //build_tabs();

    display_years();

    //set up slots
    //connect(ui->menuExisting_Labs->actions(), SIGNAL(triggered()), this, SLOT(click_lab_in_existing_labs_menu()));
    //    grad->add_class("c1",2);
    //    grad->add_section("c11","c1");
    //    grad->add_student("luisbonilla","c11","luis","lopez");
    //ui->side1->addItem(QString::fromStdString(grad->student_list()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete grad;
}



void MainWindow::on_actionLoad_New_Lab_triggered(){

    AddLabsGUI* alg = new AddLabsGUI(0, grad);
    alg->show();

    //    std::vector<std::string> s;
    //    grad->add_lab("lb1","luisbonilla","trees","1",s);
    //    ui->side2->addItem(QString::fromStdString(grad->get_lab("lb1")->get_id()));
    //    std::cout<<grad->get_lab("lb1")->get_id();
}

void MainWindow::on_actionComment_triggered(){

    if(selected_lab != nullptr){ // only open the comment engine if there is a lab
        cout<< grad <<endl;
        cout << selected_lab << endl;
        Dialog *c = new Dialog(0, grad, selected_lab);
        c->show();
    }

    //get the comment strings from the current lab and add them to the second box

}

void MainWindow::display_classes()
{
    QList<QString> ccontainer;
    ui->classlist->clear();

    if(grad->get_classes().size()>0)
    {
    std::vector<Class*> holder = grad->get_classes();

    for(Class* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->classlist->addItems(ccontainer);
    }
}

void MainWindow::display_years()
{
    QList<QString> ycontainer;
    ui->years->clear();

    if(grad->get_years().size()>0)
    {
    std::vector<Year*> holder = grad->get_years();

    for(Year* it: holder)
    {
        ycontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->years->addItems(ycontainer);
    }
}


void MainWindow::on_displayButton_clicked()
{
    ui->disjava->clear();
    QList<QString> jtcontainer;
    display_years();

    if(selected_lab != NULL)
    {
        Component* com = selected_lab->get_components().at(0);
        for(int i = 0; i<selected_lab->get_components().at(0)->get_text_lines().size(); i++)
        {
            string  javaText = to_string(i) + "     " + selected_lab->get_components().at(0)->get_text_lines().at(i);
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

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_classlist_doubleClicked(const QModelIndex &index)
{
    QList<QString> scontainer;
    ui->sectionlist->clear();
    ui->studentlist->clear();
    ui->lablist->clear();


    selected_class=grad->get_class(ui->classlist->currentItem()->text().QString::toStdString());
    std::vector<Section*> holder = selected_class->get_sections();

    for(Section* it: holder)
    {
        scontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->sectionlist->addItems(scontainer);
}

void MainWindow::on_sectionlist_doubleClicked(const QModelIndex &index)
{
    QList<QString> stcontainer;
    ui->studentlist->clear();
    ui->lablist->clear();


    selected_section=grad->get_section(ui->sectionlist->currentItem()->text().QString::toStdString());
    std::vector<Student*> holder = selected_section->get_students();

    for(Student* it: holder)
    {
        stcontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->studentlist->addItems(stcontainer);
}

void MainWindow::on_studentlist_doubleClicked(const QModelIndex &index)
{
    QList<QString> lbcontainer;
    ui->lablist->clear();


    selected_student=grad->get_student(ui->studentlist->currentItem()->text().QString::toStdString());
    std::vector<Lab*> holder = selected_student->get_labs();

    for(Lab* it: holder)
    {
        lbcontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->lablist->addItems(lbcontainer);
}

void MainWindow::on_lablist_doubleClicked(const QModelIndex &index)
{
    selected_lab=grad->get_lab(ui->lablist->currentItem()->text().QString::toStdString());
}

void MainWindow::on_disjava_doubleClicked(const QModelIndex &index)
{
    if(ui->disjava->currentItem()->backgroundColor() == Qt::red)
    {
        ui->disjava->currentItem()->setBackgroundColor(Qt::white);
    }
    else
    {
        ui->disjava->currentItem()->setBackgroundColor(Qt::red);

    }
}

void MainWindow::on_years_activated(const QString &arg1)
{

    selected_year=grad->get_year(arg1.QString::toStdString());

    QList<QString> semcontainer;
    ui->semesters->clear();
    ui->sectionlist->clear();
    ui->studentlist->clear();
    ui->lablist->clear();

   std::vector<Semester*> holder = selected_year->get_semesters();

    for(Semester* it: holder)
    {
        semcontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->semesters->addItems(semcontainer);
}

void MainWindow::on_semesters_activated(const QString &arg1)
{
    selected_semester=grad->get_semester(arg1.QString::toStdString());

    QList<QString> ccontainer;
    ui->classlist->clear();
    ui->sectionlist->clear();
    ui->studentlist->clear();
    ui->lablist->clear();

   std::vector<Class*> holder = selected_semester->get_classes();

    for(Class* it: holder)
    {
        ccontainer.append(QString::fromStdString(it->get_id()));
    }

    ui->classlist->addItems(ccontainer);
}

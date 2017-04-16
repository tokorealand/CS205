#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grad = new Grader();
    populate_existing_labs();
    build_tabs();
    std::cout<<grad->get_classes().size()<<"GGGG";

    display_classes();

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

//should eventually get a list of labs from the database and display them
void MainWindow::populate_existing_labs(){

    //sample -- load in labs
    ui->menuExisting_Labs->addAction("Lab 1");
    ui->menuExisting_Labs->addAction("Lab 2");
    ui->menuExisting_Labs->addAction("Lab 3");

    for(int i =0; i<ui->menuExisting_Labs->actions().size(); i++){
        QAction *qa = ui->menuExisting_Labs->actions().at(i);
        connect(qa,SIGNAL(triggered()), this, SLOT(click_lab_in_existing_labs_menu()));
    }
}

//slot for selecting a lab under existing labs menu
void MainWindow::click_lab_in_existing_labs_menu(){

    //get the sender- the selected lab
    QAction *selected = qobject_cast<QAction*>(sender());

    QString selected_lab_string = selected->text();

 //   ui->displayJavaText->setText("sample lab code " + selected_lab_string);

    //change the label
    ui->currentLab->setText(selected_lab_string);

    //load in lab
}

void MainWindow::build_tabs(){

    //sample tab -- delete
    ui->tabWidget->addTab(new QListWidget, "sample tab");

    if(selected_lab != nullptr){ //make sure there is a selected lab

        int noClasses = selected_lab->get_number_of_classes();

        //remove all tabs
        for(int i = 0; i < ui->tabWidget->count(); i++){
            ui->tabWidget->removeTab(i);
        }

        //build tabs
        for(int i = 0; i < noClasses; i++){

            //string s = selected_lab->get_lab_name().toStdString();
            QString tabName = QString::fromStdString(selected_lab->get_lab_name());

            //draw boxes in the tab
            ui->tabWidget->addTab(new QListWidget(), tabName);

            //load in text to all the tabs
        }
    }
}

void MainWindow::on_actionLoad_New_Lab_triggered(){

    AddLabsGUI* alg = new AddLabsGUI(0, grad);
    alg->show();

    //    std::vector<std::string> s;
    //    grad->add_lab("lb1","luisbonilla","trees","1",s);
    //    ui->side2->addItem(QString::fromStdString(grad->get_lab("lb1")->get_id()));
    //    std::cout<<grad->get_lab("lb1")->get_id();


}

void MainWindow::on_actionLoad_Lab_triggered()
{
    selectiongui *slg = new selectiongui(0, grad);
    slg->show();
    this->hide();
    while(slg->lab_selected() == false && slg->exit_pressed() == false)

    {
        QApplication::processEvents();

    }
    if(slg->exit_pressed())
    {
        delete slg;
        this->show();
        return;
    }
    selected_lab = slg->select_lab();
    selected_class = slg->select_class();

    ui->currentLab->clear();
    ui->currentLab->setText(QString::fromStdString(selected_lab->get_lab_name()));

    ui->classlist->clear();
    ui->classlist->addItem(QString::fromStdString(selected_class->get_id()));
    delete slg;
    this->show();
}


void MainWindow::on_actionAdd_Students_triggered()
{
    add_students_gui* asg = new add_students_gui(0, grad);
    asg->show();





}

void MainWindow::on_actionComment_triggered(){

    if(selected_lab != nullptr){ // only open the comment engine if there is a lab
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


void MainWindow::on_displayButton_clicked()
{
    ui->disjava->clear();
    QList<QString> jtcontainer;
    display_classes();

    if(selected_lab != NULL)
    {
        for(int i = 0; i<selected_lab->get_no_lines_in_class(0); i++)
        {
            QString  javaText = QString::fromStdString( to_string (i)+ "   " +selected_lab->get_class_code_vector().at(0).at(i)) ;
            jtcontainer.push_back(javaText);
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

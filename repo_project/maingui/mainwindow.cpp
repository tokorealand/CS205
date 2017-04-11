#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grad = new Grader();
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

void MainWindow::build_tabs(){

    if(selected_lab != nullptr){
        //load in the selected lab from the database into some kind of public object/pointer LAB CONTAINER
        int noClasses = 3;

        //remove all tabs -- WHY DOESN'T IT GO THROUGH THE LOOP ENOUGH TIMES?
        for(int i = 0; i < ui->tabWidget->count(); i++){
            ui->tabWidget->removeTab(i);
        }

        //build tabs
        for(int i = 0; i < noClasses; i++){
            QString tabName = "Class: get class name"; //figure out how you can get the class name
            ui->tabWidget->addTab(new QWidget(), tabName);
            std::cout << "add tab " << i << std::endl;

            //draw boxes in the tab

            //load in text to all the tabs
        }
    }
}

void MainWindow::on_actionLoad_New_Lab_triggered()
{
        AddLabsGUI* alg = new AddLabsGUI(0, grad);
        alg->show();

//    std::vector<std::string> s;
//    grad->add_lab("lb1","luisbonilla","trees","1",s);
//    ui->side2->addItem(QString::fromStdString(grad->get_lab("lb1")->get_id()));
//    std::cout<<grad->get_lab("lb1")->get_id();


}

void MainWindow::on_actionAdd_Students_triggered()
{
    add_students_gui* asg = new add_students_gui(0, grad);
    asg->show();
}

void MainWindow::on_actionComment_triggered(){
    Dialog *c = new Dialog(0, grad, selected_lab);
    c->show();
}


void MainWindow::on_displayButton_clicked()
{
    ui->displayJavaText->setPlainText(QString:: fromStdString(grad->get_lab("JulianBinici1")->get_java_text().at(0)));
}

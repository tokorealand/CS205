#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grad = new Grader();
    populate_existing_labs();
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

    ui->menuExisting_Labs->addAction("Lab 1");
    ui->menuExisting_Labs->addAction("Lab 2");
    ui->menuExisting_Labs->addAction("Lab 3");

}

void MainWindow::click_lab_in_existing_labs_menu(){

    //get the sender- the selected lab
    QAction *selected = qobject_cast<QAction*>(sender());

    QString selected_lab_string = selected->text();

    //ui->listWidget->addItem(selected_lab_string);

    //change the label
    ui->currentLab->setText(selected_lab_string);

    //load_random_lab();
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
    if(selected_lab != nullptr){ // only open the comment engine if there is a lab
        Dialog *c = new Dialog(0, grad, selected_lab);
        c->show();
    }

    //get the comment strings from the current lab and add them to the second box

}


void MainWindow::on_displayButton_clicked()
{
    ui->displayJavaText->setPlainText(QString:: fromStdString(grad->get_lab("Julian_Binici_1")->get_java_text().at(0)));
}

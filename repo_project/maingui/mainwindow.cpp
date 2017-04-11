#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setStyleSheet(
             "background-image:url(\"/home/worklu/repo_lopez_mullan_lickfeld_binici/repo_project/maingui/minb.jpg\"); background-position: center;" );
    ui->setupUi(this);

    add_existing_lab_list();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_existing_lab_list(){

    //draw the lab list from the database, create a qstringlist
    labStringList.append("Lab 1");
    labStringList.append("Lab 2");
    labStringList.append("Lab 3");

    //add the labs to the gui
    for(int i = 0; i<labStringList.size(); i++){
        QString s = labStringList.at(i);
        ui->menuExisting_Labs->addAction(s);
    }

    //add the triggers for labs in the menu item
    for(int i = 0; i < labStringList.size(); i++){
        QAction *qa = ui->menuExisting_Labs->actions().at(i);
        connect(qa, SIGNAL(triggered()), this, SLOT(load_lab()));
    }

    //add the triggers to the QAction menu items
     connect(ui->actionAdd_New_Lab, SIGNAL(triggered()), this, SLOT(add_new_labs()));
     connect(ui->actionAdd_Students, SIGNAL(triggered()), this, SLOT(add_students()));
     connect(ui->actionLoad_Random_Lab, SIGNAL(triggered()), this, SLOT(load_random_lab()));
     connect(ui->actionComment, SIGNAL(triggered()), this, SLOT(comment()));
     connect(ui->actionHighlight, SIGNAL(triggered()), this, SLOT(highlight()));
}

//slots
void MainWindow::load_lab(){

    //get the sender- the selected lab
    selected_lab = qobject_cast<QAction*>(sender());

    selected_lab_string = selected_lab->text();

    ui->listWidget->addItem(selected_lab_string);

    //change the label
    ui->label_2->setText(selected_lab_string);

    load_random_lab();
}

void MainWindow::add_new_labs(){
    WidgetA *w = new WidgetA(0);
    w->show();
}

void MainWindow::add_students(){
    AddStudentsGUI*w = new AddStudentsGUI(0);
    w->show();
}

void MainWindow::load_random_lab(){
    //lab vector
    build_tabs();
}

void MainWindow::comment(){

}

void MainWindow::highlight(){

}

void MainWindow::build_tabs(){

    if(selected_lab){
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
            cout << "add tab " << i << endl;

            //draw boxes in the tab

            //load in text to all the tabs
        }
    }
}

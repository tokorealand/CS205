#include "mainmenugui.h"
#include "ui_mainmenugui.h"

MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    ui->setupUi(this);
}

MainMenuGUI::~MainMenuGUI()
{
    delete ui;
}

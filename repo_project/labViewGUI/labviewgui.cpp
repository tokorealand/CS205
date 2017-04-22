#include "labviewgui.h"
#include "ui_labviewgui.h"

labViewGUI::labViewGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labViewGUI)
{
    ui->setupUi(this);
}

labViewGUI::~labViewGUI()
{
    delete ui;
}

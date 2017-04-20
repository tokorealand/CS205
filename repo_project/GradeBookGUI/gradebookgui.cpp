#include "gradebookgui.h"
#include "ui_gradebookgui.h"

GradeBookGUI::GradeBookGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradeBookGUI)
{
    ui->setupUi(this);
}

GradeBookGUI::~GradeBookGUI()
{
    delete ui;
}

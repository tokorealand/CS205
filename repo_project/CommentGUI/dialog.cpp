#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Grader *aGrader, Lab *aLab) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    grader = aGrader;
    lab = aLab;
    populate();
}

Dialog::~Dialog()
{
    delete ui;
}

//populate the gui with info
void Dialog::populate(){
    //populate the commentList with comments from the database
    commentQStringList.append("comment one");
    commentQStringList.append("comment two");
    commentQStringList.append("comment three");
    commentQStringList.append("comment four");
    commentQStringList.append("and five");
    commentQStringList.append("now six");
    commentQStringList.append("this is seven");
    commentQStringList.append("last comment 8");
    ui->commentList->addItems(commentQStringList);

    //populate the rubricSectionsDropDown with rubric sections
    ui->rubricSectionDropDown->insertItem(0,"section 1", QVariant(0));
    ui->rubricSectionDropDown->insertItem(1,"section 2", QVariant(0));
    ui->rubricSectionDropDown->insertItem(2,"section 3", QVariant(0));

    //populate the colorDropDown with colors from the rubric section
    ui->colorDropDown->insertItem(0,"red", QVariant(0));
    ui->colorDropDown->insertItem(1,"green", QVariant(0));
    ui->colorDropDown->insertItem(2,"blue", QVariant(0));
}


void Dialog::on_doneButton_clicked(){

    //save comment details -- will be in a vector of comments in lab object
    string commentText;

    if(ui->commentList->selectedItems().size() = 0){
    }// ui->commentText->text().toStdString();

    string rubricSection    = ui->rubricSectionDropDown->currentText().toStdString();
    double pointsDeducted   = ui->pointsOffSpinBox->value();
    string highlightColor   = ui->colorDropDown->currentText().toStdString();
    //lab->create_comment(commentText, rubricSection, pointsDeducted, highlightColor);
    //grader->add_comment(commentText, rubricSection, pointsDeducted, highlightColor);
    //close the window
    close();
}

void Dialog::populate_comment_list(){
    ui->commentList->clear();
    ui->commentList->addItems(commentQStringList);
}

void Dialog::on_commentText_textChanged(const QString &arg1){

    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->commentList->clear();
    ui->commentList->addItems(commentQStringList.filter(regExp));
}

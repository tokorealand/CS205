#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Grader *aGrader, Lab *aLab) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    grader = aGrader;
    lab = aLab;
    //ui->commentList->setSelectionMode(QAbstractItemView::ExtendedSelection);
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
    string commentId        = lab->get_id() + to_string(lab->get_comment_vector().size());
    string labId            = lab->get_id();
    string lineNumber       = ui->lineNo->text().toStdString();
    string commentText      = ui->commentText->text().toStdString(); //save what's in the box
    string rubricSection    = ui->rubricSectionDropDown->currentText().toStdString();
    string highlightColor   = ui->colorDropDown->currentText().toStdString();
    string pointsDeducted   = to_string(ui->pointsOffSpinBox->value());

    //add the comment
    grader->add_comment(commentId, labId, lineNumber, commentText, rubricSection, highlightColor, pointsDeducted);

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

void Dialog::on_commentList_clicked(const QModelIndex &index)
{
    QString s = ui->commentList->selectedItems().at(0)->text();
    ui->commentText->setText(s);
}

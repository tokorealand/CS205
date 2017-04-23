#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Grader *aGrader, Lab *aLab, Component *aComponent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    grader = aGrader;
    lab = aLab;
    populate();
    component = aComponent;
}

Dialog::~Dialog(){
    delete ui;
}

//populate the gui with info
void Dialog::populate(){

    //populate the commentList with comments from the database
    for(int i = 0; i < lab->get_rubric()->get_rubric_sections().size(); i++){
        QString temp = QString::fromStdString(lab->get_rubric()->get_section_at(i));
        ui->commentList->insertItem(i, temp);
    }

    //populate the rubricSectionsDropDown with rubric sections
    for(int i = 0; i<lab->get_rubric()->get_rubric_sections().size(); i++){
        QString temp = QString::fromStdString(lab->get_rubric()->get_section_text_at(i));
        ui->rubricSectionDropDown->insertItem(i, temp);
    }
}

void Dialog::on_doneButton_clicked(){

    //save comment details -- will be in a vector of comments in lab object
    string commentId        = lab->get_id() + to_string(lab->get_comment_vector().size());
    cout << "component " << component << endl;
    string componentId      = component->get_id();
    string lineNumber       = ui->lineNo->text().toStdString();
    string commentText      = ui->commentText->text().toStdString(); //save what's in the box
    string rubricSection    = ui->rubricSectionDropDown->currentText().toStdString();
    string highlightColor   = ui->colorDropDown->currentText().toStdString();
    string pointsDeducted   = to_string(ui->pointsOffSpinBox->value());

    //add the comment
    grader->add_comment(commentId, componentId, lineNumber, commentText, rubricSection, highlightColor, pointsDeducted);

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

void Dialog::on_commentList_clicked(const QModelIndex &index){

    QString s = ui->commentList->selectedItems().at(0)->text();
    ui->commentText->setText(s);
}

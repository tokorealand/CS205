#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Grader *aGrader, Lab *aLab, Component *aComponent, Class *aclass) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    grader = aGrader;
    lab = aLab;
    this->aclass=aclass;
    component = aComponent;
    populate();

}

Dialog::~Dialog(){
    delete ui;
}

//populate the gui with info
void Dialog::populate(){

    QList<QString> ccontainer;
    ui->commentList->clear();

    if(grader->get_comments().size()>0)
    {
        std::vector<Comment*> holder = grader->get_comments();

        for(Comment* it: holder)
        {
            ccontainer.append(QString::fromStdString(it->get_comment_text()));
        }

        ui->commentList->addItems(ccontainer);
    }

    //populate the rubric drop down
        //get the rubric from this class and lab
        vector<RubricObject*> tempRV = aclass->get_rubrics();
        RubricObject *tempR = tempRV.at(0);
        //RubricObject *tempR = currentClass->get_rubrics().at(stoi(lab->get_lab_num()));

        QStringList tempRSections;

        //add the text of each rubric section to a qstring list
        for(int i = 0; i < tempR->get_rubric_sections().size(); i++){

            //get the text of a rubric section
            vector<RubricSection*> rsv = tempR->get_rubric_sections();
            RubricSection *rs = rsv.at(i);
            string s = rs->get_description();
            std::cout<<"thisthingisweird";
            QString sectionText = QString::fromStdString(s);

            //add the text of a rubric section to a temporary list
            tempRSections.push_back(sectionText);
        }

        //add the contents of the temp list to the dropdown
        ui->rubricSectionDropDown->addItems(tempRSections);
    }


void Dialog::on_doneButton_clicked(){

    //save comment details -- will be in a vector of comments in lab object

    string commentId        = to_string(component->get_comments().size())+"_"+component->get_id();
    string componentId      = component->get_id();
    string lineNumber       = ui->lineNo->text().toStdString();
    cout << "1" <<endl;
    string commentText      = ui->commentText->text().toStdString(); //save what's in the box
    cout << "2" <<endl;
    string rubricSection    = ui->rubricSectionDropDown->currentText().toStdString();
    cout << "3" <<endl;
    string highlightColor   = ui->colorDropDown->currentText().toStdString();
    cout << "4" <<endl;
    string pointsDeducted   = to_string(ui->pointsOffSpinBox->value());
    cout << "5" <<endl;

    //add the comment
    grader->add_comment(commentId, componentId, lineNumber, commentText, rubricSection, highlightColor, pointsDeducted);
    cout << "6" <<endl;

    //close the window
    close();
}

void Dialog::populate_comment_list(){

    ui->commentList->clear();
    ui->commentList->addItems(commentQStringList);
}

void Dialog::on_commentText_textChanged(const QString &arg1){

    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    //cout << "arg1" << arg1;
    ui->commentList->clear();
    ui->commentList->addItems(commentQStringList.filter(regExp));
}

void Dialog::on_commentList_clicked(const QModelIndex &index){

    QString s = ui->commentList->selectedItems().at(0)->text();
    ui->commentText->setText(s);
}

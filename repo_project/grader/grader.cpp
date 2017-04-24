#include "grader.h"

Grader::Grader()
{

    tool = new DBTool("TEgfST45");


    tool = new DBTool("TEST900");

    tool = new DBTool("TEST9000");


    control = new Controller(tool);
    fp = new FileParser("students.txt", this);

}

Grader::~Grader()
{
    delete control;
    delete tool;
}

std::string Grader::student_list()
{
    return control->student_list();
}

vector<Year*> Grader::get_years()
{
    return control->get_years();

}

vector<Semester*> Grader::get_semesters()
{
    return control->get_semesters();

}

vector<Comment*> Grader::get_comments()
{
    return control->get_comments();
}




void Grader::add_year(string yearID)
{
    control->add_year(yearID);
}

void Grader::add_semester(string semesterID,string yearID)
{
    control->add_semester(semesterID,yearID);
}

void Grader::add_class(string classID,std::string semesterid)
{
    control->add_class(classID,semesterid);
}

void Grader::add_section(std::string sectionID, string classID)
{

    control->add_section(sectionID,classID);
}

void Grader::add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname)
{

    control->add_student(studentID, sectionID, firstname, lastname);
}

void Grader::add_lab(std::string labID, string studentID, string labName, string labNumber)
{
    control->add_lab(labID, studentID,labName,labNumber);
}

void Grader::add_component(std::string componentID, std::string labID, std::string text)
{
    control->add_component(componentID,labID, text);

}

void Grader::add_comment(std::string commentID, std::string labID, std::string linenumber,std::string commentphrase, std::string rubricsection,std::string highlight, std::string points)
{
    cout << "7" << endl;
    control->add_comment( commentID,  labID,  linenumber,commentphrase,  rubricsection, highlight, points);
}

void Grader::add_rubric(string rubricID, string classID)
{
    control->add_rubric(rubricID, classID);
}

void Grader::add_rubricsection(string rubricsectionID, string rubricID, string description, string points, string color)
{
    control->add_rubricsection(rubricsectionID, rubricID, description,points,color);
}


/**
 *
 * GET METHODS
 *
 */

Year* Grader::get_year(string id)
{

   return control->get_year(id);
}

Semester* Grader::get_semester(string id)
{
   return  control->get_semester(id);
}
Class* Grader::get_class(string id)
{
    return control->get_class(id);
}

Section* Grader::get_section(string id)
{
    return control->get_section(id);
}

Student* Grader::get_student(string id)
{
    return control->get_student(id);
}

Lab* Grader::get_lab(string id)
{
    return control->get_lab(id);
}

Component* Grader::get_component(string id)
{
    return control->get_component(id);
}

Comment* Grader::get_comment(string id)
{
    return control->get_comment(id);
}

RubricObject* Grader::get_rubric(string id)
{
    return control->get_rubric(id);
}

RubricSection* Grader::get_rubricsection(string id)
{
    return control->get_rubricsection(id);
}

FileParser* Grader::get_file_parser(){
    return fp;
}

vector<Class*> Grader::get_classes()
{
    return control->get_classes();
}

void Grader::add_lab_name(string name){
    listOfLabNames.push_back(name);
}

vector<string> Grader::get_lab_name_list(){
    return listOfLabNames;
}

Controller* Grader::get_control(){
    return control;
}

void Grader::add_temp_rubric(RubricObject *r){
    tempRubric = r;
}

RubricObject* Grader::get_temp_rubric(){
    return tempRubric;
}


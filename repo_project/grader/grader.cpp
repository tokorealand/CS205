#include "grader.h"

Grader::Grader()
{
    tool = new DBTool("Grader");
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



void Grader::add_class(string classID, int number_of_sections)
{
    control->add_class(classID,number_of_sections);
}

void Grader::add_section(std::string sectionID, string classID)
{

    control->add_section(sectionID,classID);
}

void Grader::add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname)
{

    control->add_student(studentID, sectionID, firstname, lastname);
}

void Grader::add_lab(std::string labID, string studentID, string labName, string labNumber, vector<vector<string>> javaFiles)
{
    control->add_lab(labID, studentID,labName,labNumber, javaFiles);
}

void Grader::add_component(std::string componentID, std::string labID, std::string compath)
{
    control->add_component(componentID,labID,  compath);
}

void Grader::add_comment(std::string commentID, std::string labID, std::string linenumber,std::string commentphrase, std::string rubricsection,std::string highlight, std::string points)
{
    control->add_comment( commentID,  labID,  linenumber,commentphrase,  rubricsection, highlight, points);
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

FileParser* Grader::get_file_parser()
{
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

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

void Grader::add_lab(std::string labID, string studentID, string labName, string labNumber, vector<string> javaText)
{
    control->add_lab(labID, studentID,labName,labNumber, javaText);
}

void Grader::add_component(std::string componentID, std::string labID, std::string compath)
{
    control->add_component(componentID,labID,  compath);
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

FileParser* Grader::get_file_parser()
{
    return fp;
}

#ifndef GRADER_H
#define GRADER_H
#include "section.h"
#include "student.h"
#include "class.h"
#include "dbtable.h"
#include "dbtool.h"
#include "../controller/controller.h"
#include "lab.h"
#include "fileparser.h"

#include <vector>
#include <string>
using namespace std;

class FileParser;
class Controller;
class Grader{
private:

    Student* currentStudent;
    Lab* currentLab;
    DBTool *tool;
    Controller *control;
    FileParser* fp;

    vector<string> listOfLabNames;


public:
    Grader();
    ~Grader();


    void set_current_student(Student*);
    void set_currentLab(Lab*);

    void add_comment(std::string commentID, std::string labID, std::string linenumber,std::string commentphrase, std::string rubricsection,std::string highlight, std::string points);

    void add_component(std::string componentID, string labID, string compath, vector<string> javaLine);

    void add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname);

    void add_lab(std::string labID, std::string studentID, std::string labName, std::string labNumber);

    void add_section(std::string sectionID, std::string classID);

    void add_class(std::string classID, int number_of_sections);

    std::string student_list();



    Class* get_class(std::string id);

    Section* get_section(std::string id);

    Student* get_student(std::string id);

    Lab* get_lab(std::string id);

    Component* get_component(std::string id);

    Comment* get_comment(std::string id);

    Controller* get_control();

    FileParser* get_file_parser();

    void add_lab_name(string name);

    vector<string> get_lab_name_list();

    vector<Class*> get_classes();




};




#endif // GRADER_H

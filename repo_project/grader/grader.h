#ifndef GRADER_H
#define GRADER_H
#include "section.h"
#include "student.h"
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



public:
    Grader();
    ~Grader();


    void set_current_student(Student*);
    void set_currentLab(Lab*);

    void add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname);

    void add_lab(std::string labID, std::string studentID, std::string labName, std::string labNumber, vector<string> javaText);

    void add_section(std::string sectionID, std::string classID);

    void add_class(std::string classID, int number_of_sections);



    Class* get_class(std::string id);

    Section* get_section(std::string id);

    Student* get_student(std::string id);

    Lab* get_lab(std::string id);

};




#endif // GRADER_H

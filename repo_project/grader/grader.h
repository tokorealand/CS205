#ifndef GRADER_H
#define GRADER_H
#include "section.h"
#include "student.h"
#include "dbtable.h"
#include "dbtool.h"
#include "../controller/controller.h"
#include "lab.h"
#include <vector>
#include <string>
using namespace std;

class Controller;
class Grader{
private:

    Student* currentStudent;
    Lab* currentLab;
    DBTool *tool;
    Controller *control;



public:
    Grader();
    ~Grader();


    void set_current_student(Student*);
    void set_currentLab(Lab*);





};




#endif // GRADER_H

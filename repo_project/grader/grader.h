#ifndef GRADER_H
#define GRADER_H
#include "section.h"
#include "student.h"
#include "lab.h"
#include <vector>
#include <string>
using namespace std;

class Grader{
private:
    vector<Section*> sections;
    Student* currentStudent;
    Lab* currentLab;

public:
    Grader();
    ~Grader();

    void add_section(Section*);
    void set_current_student(Student*);
    void set_currentLab(Lab*);






};

#endif // GRADER_H

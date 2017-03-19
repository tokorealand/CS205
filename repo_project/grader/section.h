#ifndef SECTION_H
#define SECTION_H

#include "student.h"
#include <vector>
#include <string>
using namespace std;

class Section{

private:
    string id;
    vector<Student*> students;

public:
    Section(string);
    ~Section();

    void add_student(Student*);
    vector<Student*> get_students();
    string get_id();

};

#endif // SECTION_H

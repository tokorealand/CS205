#ifndef STUDENT_H
#define STUDENT_H


#include "lab.h"
#include <vector>
#include <string>

using namespace std;
class Student{

private:
    vector<Lab*> labs;
    string firstName;
    string lastName;


public:
    Student(string, string);
    ~Student();

    string get_first_name();
    string get_last_name();
    void add_lab(Lab*);
    vector<Lab*> get_labs();

};

#endif // STUDENT_H

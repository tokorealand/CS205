#ifndef LAB_H
#define LAB_H

#include <vector>
#include <string>
using namespace std;

class Lab{
 private:
    int labNum;
    int grade;

public:
    Lab(int);
    ~Lab();

    void set_grade(int);
    int get_grade();

};

#endif // LAB_H

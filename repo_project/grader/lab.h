#ifndef LAB_H
#define LAB_H

#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"
#include "student.h"

using namespace std;
class Student;

class Lab : public DBTable{
private:
    std::string labNum;
    int grade;
    std::string labName;
    std::string id;
    std::string studentID;
    Student *belongs = nullptr; //student pointer of whose lab it is.



public:
    Lab(string labID, std::string studentID, string labName, string labNumber, DBTool *tool, std::string table);
    ~Lab();

    std::string get_lab_name;
    int get_lab_num();

    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(string id, string studentid, std::string labname, std::string labnumber);
    void set_grade(int);
    int get_grade();

};

int cb_add_row_lab(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);

#endif // LAB_H

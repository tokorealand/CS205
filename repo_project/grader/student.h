#ifndef STUDENT_H
#define STUDENT_H


#include "lab.h"
#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"


/**
The Student class is an object representation of a container to hold Labs.
@author Luis Lopez-Bonilla
@version 1.0 (April 25 2017)
*/
class Lab;

using namespace std;
class Student : public DBTable{

private:
    vector<Lab*> labs;
    string firstName;
    string lastName;
    string sectionID;
    string id;
    int numLabs;
protected:
    std::string sql_select_all;


public:
    Student(string studentID, string sectionID, string firstname, string lastname, DBTool *tool, std::string table);
    ~Student();

    string get_first_name();
    string get_last_name();
    void add_lab(Lab *thelab);
    string get_id();
    string get_section_id();
    vector<Lab*> get_labs();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(string id, string sectionID, std::string firstname, std::string lastname);

};

int cb_add_row_student(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // STUDENT_H

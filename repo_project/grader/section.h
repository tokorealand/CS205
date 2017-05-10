#ifndef SECTION_H
#define SECTION_H

#include "student.h"
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
The Section class is an object representation of a container to hold students.
@author Luis Lopez-Bonilla
@version 1.0 (April 25 2017)
*/
using namespace std;

class Student;
class Lab;

class Section : public DBTable
{

private:
    std::string id;
    std::string classID;
    DBTool *tool;
    vector<Student*> students;
    vector<Lab*> labs;
    std::string name;


protected:
    std::string sql_select_all;

public:
    Section();
    Section(std::string sectionID,std::string classID, DBTool *tool, std::string table);
    ~Section();

    void add_student(Student* student);


    std::string get_name();
    vector<Student*> get_students();
    string get_id();
    string get_class_id();
    void repopulate();
    bool check_for_student(string studentid);

    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();

    bool add_row(std::string id, std::string classid);

};


int cb_add_row_section(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // SECTION_H

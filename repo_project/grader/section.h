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
using namespace std;

class Student;
class Lab;

class Section : public DBTable
{

private:
    int id;
    DBTool *tool;
    vector<Student*> students;
    vector<Lab*> labs;

    Student* get_student(string fn, string ln);
    string table_students = "stable";
    string table_sections = "ltable";
    string table_labs;
    bool select_all_students_in_section();
    bool select_all_labs_in_section();
    bool drop_student_table();
    bool drop_lab_table();

    std::string sql_select_all_students_in_section;
    std::string sql_select_all_labs_in_section;


public:
    Section();
    Section(int id,DBTool *tool);
    ~Section();

    void add_student(std::string fn, std::string ln);
    void add_lab_student(std::string fn, std::string ln, std::string labname, int labnumber);


    vector<Student*> get_students();
    string get_id();
    void repopulate();

    bool add_row(int id);

};

int cb_select_all_students_in_section(void  *data,
               int    argc,
               char **argv,
               char **azColName);

int cb_select_all_labs_in_section(void  *data,
               int    argc,
               char **argv,
               char **azColName);

#endif // SECTION_H

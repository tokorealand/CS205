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
    std::string id;
    std::string classID;
    DBTool *tool;
    vector<Student*> students;
    vector<Lab*> labs;

//    Student* get_student(string fn, string ln);
//    string table_students = "stable";
//    string table_labs = "ltable";
//    bool select_all_students_in_section();
//    bool select_all_labs_in_section();
//    bool drop_student_table();
//    bool drop_lab_table();

//    std::string sql_select_all_students_in_section;
//    std::string sql_select_all_labs_in_section;

protected:
    std::string sql_select_all;

public:
    Section();
    Section(std::string sectionID,std::string classID, DBTool *tool, std::string table);
    ~Section();

    void add_student(Student* student);
//    void add_student_db(std::string fn, std::string ln);


//    void add_lab_student(std::string fn, std::string ln, std::string labname);

//    void add_lab_student(std::string fn, std::string ln, std::string labname, int labnumber);

//    void increment_student();


    vector<Student*> get_students();
    string get_id();
    void repopulate();
    bool check_for_student(string studentid);

    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();

    bool add_row(std::string id, std::string classid);

};

int cb_select_all_students_in_section(void  *data,
                                      int    argc,
                                      char **argv,
                                      char **azColName);

int cb_select_all_labs_in_section(void  *data,
                                  int    argc,
                                  char **argv,
                                  char **azColName);

int cb_add_row_section(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // SECTION_H

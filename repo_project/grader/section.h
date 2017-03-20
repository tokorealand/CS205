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

class Section : public DBTable
{

private:
    string id;
    vector<Student*> students;

protected:
    std::string sql_select_all;

public:
    Section();
    Section(string id,DBTool *tool, std::string table);
    ~Section();

    void add_student(Student*);
    vector<Student*> get_students();
    string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(int id);

};

int cb_add_row(void  *data,
               int    argc,
               char **argv,
               char **azColName);

#endif // SECTION_H

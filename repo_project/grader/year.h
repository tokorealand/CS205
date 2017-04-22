#ifndef YEAR_H
#define YEAR_H
#include "semester.h"
#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"

class Semester;

class Year : public DBTable
{


private:

    std::string id;
    DBTool *tool;
    vector<Semester*> semester;


protected:
    std::string sql_select_all;
public:
    Year();
    Year(std::string id, DBTool *tool, std::string table);
    ~Year();

    void add_semester(Semester* sem);
    Semester* get_semester(int semesterid);

    std::vector<Semester*> get_semesters();


    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();
    std::string get_id();
    bool add_row(std::string id);
};

int cb_add_row_year(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // YEAR_H

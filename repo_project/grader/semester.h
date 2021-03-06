#ifndef SEMESTER_H
#define SEMESTER_H
#include "class.h"
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
The Semester class is an object representation of a container to hold Classes.
@author Luis Lopez-Bonilla
@version 1.0 (April 25 2017)
*/
class Class;
class Semester : public DBTable
{

private:

    std::string id;
    std::string yearid;
    DBTool *tool;
    vector<Class*> classes;
    std::string name;

protected:
    std::string sql_select_all;

public:
    Semester();
    Semester(std::string id, std::string yearid,DBTool *tool, std::string table);
~Semester();
    void add_class(Class* cla);
    Class* get_class(int classid);

    std::vector<Class*> get_classes();
    std::string get_name();


    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();
    std::string get_id();
    bool add_row(std::string id, std::string yearid);

};

int cb_add_row_semester(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);


#endif // SEMESTER_H

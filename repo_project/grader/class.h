#ifndef CLASS_H
#define CLASS_H
#include "section.h"
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

class Section;

class Class : public DBTable
{

private:

    std::string id;
    int number_of_sections = 0;
    DBTool *tool;
    vector<Section*> sections;


protected:
    std::string sql_select_all;

public:
    Class();
    Class(std::string classID,int number_of_sections,DBTool *tool, std::string table);
    ~Class();

    void add_section();
    Section* get_section(int sectionid);


    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();
    std::string get_id();
    bool add_row(std::string id, int number_of_sections);

  //  void increment_section();


};

int cb_add_row_class(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // CLASS_H

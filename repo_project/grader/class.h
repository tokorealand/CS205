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
    //int sectioncounter = 0;
    int sc = 0;
    int lc = 0;
    int* studentcounter = &sc;
    int* labcounter = &lc;
    std::string id;
    int number_of_sections = 0;
    DBTool *tool;
    vector<Section*> sections;
    std::string table_section = "sectiontable";
    bool select_all_sections_in_class();
    bool drop_section_table();
    std::string sql_select_all_sections_in_class;
    void repopulate();

protected:
    std::string sql_select_all;

public:
    Class();
    Class(std::string classID,int number_of_sections,DBTool *tool, std::string table);
    ~Class();

    void add_section();
    Section* get_section(int sectionid);
    void increment_student();
    int sectioncounter = 0;

    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();

    bool add_row(std::string id, int number_of_sections);

  //  void increment_section();


};

int cb_add_row_class(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // CLASS_H

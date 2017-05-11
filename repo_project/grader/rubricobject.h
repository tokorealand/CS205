#ifndef RUBRICOBJECT_H
#define RUBRICOBJECT_H

#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"
#include "rubricsection.h"



using namespace std;

class RubricSection;


class RubricObject : public DBTable
{

public:
    //constructors
    RubricObject(std::string id, std::string classID,DBTool *tool, std::string table);

    ~RubricObject();

    void operator=(RubricObject &obj); //copy assignment

    //getters
    vector<RubricSection *> get_rubric_sections();
    int get_total_points();
    string get_section_at(int i);
    string get_section_text_at(int i);
    string get_color_at(int i);
    int get_size();
    string get_name();
    string get_class_id();
    //setters
    void add_rubric_section(RubricSection* rsec);
    void set_deleted();





    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(string id, string classid);

    int size = 0;

private:
    vector<RubricSection*> rubricSections;
    DBTool *tool;
    std::string table;
    std::string id;
    std::string classid;
    std::string name;
    int total=0;
    bool deleted;

};

int cb_add_row_rubric(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);

#endif // RUBRICOBJECT_H

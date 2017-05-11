#ifndef CLASS_H
#define CLASS_H
#include "section.h"
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
#include "rubricobject.h"

/**
The Class class is an object representation of a conntainer to hold sections and
to evaluate statistics of submitted assignments.
@author Luis Lopez-Bonilla
@version 1.0 (April 25 2017)
*/
using namespace std;

class Section;
class Lab;

class Class : public DBTable
{

private:

    std::string id;
    std::string semesterid;
    DBTool *tool;
    vector<Section*> sections;
    vector<Lab*> labs;
    std::string name;
    vector<RubricObject*> rubrics;


protected:
    std::string sql_select_all;

public:
    Class();
    Class(std::string classID,std::string semesterid,DBTool *tool, std::string table);
    ~Class();

    void add_section(Section* sec);
    void add_lab(Lab* lab);
    Section* get_section(int sectionid);

    std::vector<Section*> get_sections();
    std::vector<Lab*> get_labs();
    std::string get_name();
    std::string labnumber;
    std::vector<RubricObject*> get_rubrics();
    void add_rubric(RubricObject* rubric);
    int count_lab_matching_key(string labnum);
    bool check_all_matching_key_graded(string labnum);
    double get_amount_graded(string labnum);
    void update_lab_totals(int labnum, int total);



    // create command for your child class.
    void store_create_sql();

    void store_add_row_sql();
    std::string get_id();
    bool add_row(std::string id, std::string semesterid);



};

int cb_add_row_class(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // CLASS_H

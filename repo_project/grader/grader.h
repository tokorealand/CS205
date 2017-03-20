#ifndef GRADER_H
#define GRADER_H
#include "section.h"
#include "student.h"
#include "dbtable.h"
#include "dbtool.h"
#include "lab.h"
#include <vector>
#include <string>
using namespace std;

class Grader : public DBTable{
private:
    vector<Section*> sections;
    Student* currentStudent;
    Lab* currentLab;
    DBTool *tool;
    std::string sql_select_all_pgh;
    std::string sql_select_all_g;

public:
    Grader();
    Grader(DBTool *db);
    ~Grader();

    void add_section(Section*);
    void set_current_student(Student*);
    void set_currentLab(Lab*);





};


int cb_select_all_students(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName);

int cb_select_all_sections(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName);

#endif // GRADER_H

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../grader/section.h"
#include "../grader/student.h"
#include "../grader/dbtable.h"
#include "../grader/dbtool.h"
#include "../grader/lab.h"
#include "../grader/class.h"
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <string>

class Controller : public DBTable{

private:
    std::vector<Class*> classes;
    std::vector<Section*> sections;
    std::vector<Student*> students;
    std::vector<Lab*> labs;

    std::string table_class = "classtable";
    std::string table_section = "sectiontable";
    std::string table_student = "studenttable";
    std::string table_lab = "labtable";

    DBTool *class_tool;

    bool select_all_classes();
    bool drop_class_table();
    std::string sql_select_all_classes;

    bool select_all_sections();
    bool drop_section_table();
    std::string sql_select_all_sections;

    bool select_all_students();
    bool drop_student_table();
    std::string sql_select_all_students;

    bool select_all_labs();
    bool drop_lab_table();
    std::string sql_select_all_labs;

    bool item_exist(std::string id, std::string type);

    void total_drop();




protected:
    std::string sql_select_all;


public:
    Controller();
    Controller(DBTool *db);
    ~Controller();

    /* String version of the creation methods.
     *
     **/
    void add_class(std::string classID, int number_of_sections);

    void add_section(std::string sectionID, std::string classID);

    void add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname);

    void add_lab(std::string labID, std::string studentID, std::string labName, std::string labNumber);


    /* Pointer version of the creation methods.
     *
     **/

    void add_section(std::string sectionID, Class* section_of_class);

    void add_student(std::string studentID,Section *student_of_section, std::string firstname, std::string lastname, DBTool *tool, std::string table);

    void add_lab(std::string labID, Student* lab_of_student, std::string labName, std::string labNumber, DBTool *tool, std::string table);



};

int cb_select_all_classes(void  *data,
                          int    argc,
                          char **argv,
                          char **azColName);

int cb_select_all_sections(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName);

int cb_select_all_students(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName);

int cb_select_all_labs(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // CONTROLLER_H

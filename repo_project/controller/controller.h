#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../grader/section.h"
#include "../grader/student.h"
#include "../grader/dbtable.h"
#include "../grader/dbtool.h"
#include "../grader/lab.h"
#include "../grader/class.h"
#include "../grader/semester.h"
#include "../grader/year.h"
#include "../grader/component.h"
#include "../grader/commentengine.h"
#include "../grader/comment.h"
#include "../grader/rubricobject.h"
#include "../grader/rubricsection.h"
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <string>


/**
The Controller class keeps tracks of all the objects and holds all the methods
for basic manipulations of these objects...such as adding and getting.
@author Luis Lopez-Bonilla
@version 1.0 (April 25 2017)
*/
class Controller : public DBTable{

private:
    std::vector<Year*> years;
    std::vector<Semester*> semesters;
    std::vector<Class*> classes;
    std::vector<Section*> sections;
    std::vector<Student*> students;
    std::vector<Lab*> labs;
    std::vector<Component*> components;
    std::vector<Comment*> comments;
    std::vector<RubricObject*> rubrics;
    std::vector<RubricSection*> rubricsections;


    //Database table names
    std::string table_year = "yeartable";
    std::string table_semester = "semestertable";
    std::string table_class = "classtable";
    std::string table_section = "sectiontable";
    std::string table_student = "studenttable";
    std::string table_lab = "labtable";
    std::string table_component = "componenttable";
    std::string table_comment = "commenttable";
    std::string table_rubric = "rubrictable";
    std::string table_rubricsection = "rubricsectiontable";



    DBTool *class_tool;

    /**
     * The methods to interact with the database.
     */
    bool select_all_years();
    bool drop_year_table();
    std::string sql_select_all_year;

    bool select_all_semesters();
    bool drop_semester_table();
    std::string sql_select_all_semester;

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

    bool select_all_components();
    bool drop_component_table();
    std::string sql_select_all_components;

    bool select_all_commentss();
    bool drop_comments_table();
    std::string sql_select_all_comments;

    bool select_all_rubrics();
    bool drop_rubrics_table();
    std::string sql_select_all_rubrics;

    bool select_all_rubricsections();
    bool drop_rubricsections_table();
    std::string sql_select_all_rubricsections;




    void total_drop();





protected:
    std::string sql_select_all;


public:
    Controller();
    Controller(DBTool *db);
    ~Controller();
    void total_recall();
    void test_drop();


    /* String version of the creation methods.
     *
     **/

    bool item_exist(std::string id, std::string type);

    bool add_year(std::string yearID);

    bool add_semester(std::string semesterID, std::string yearID);

    bool add_class(std::string classID,std::string semesterID);

    bool add_section(std::string sectionID, std::string classID);

    bool add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname);

    bool add_lab(std::string labID, std::string studentID, std::string labName, std::string labNumber, std::string graded);

    bool add_component(std::string componentID, std::string labID, std::string text);

    bool add_comment(std::string commentID, std::string labID, std::string linenumber, std::string commentphrase, std::string rubricsection, std::string highlight, string points);

    bool add_rubric(std::string rubricID, std::string classID);

    bool add_rubricsection(std::string rubricsectionID, std::string rubricID,std::string description, std::string points, std::string color);

    std::string student_list();





    Year* get_year(std::string id);
    Semester* get_semester(std::string id);
    Class* get_class(std::string id);
    Section* get_section(std::string id);
    Student* get_student(std::string id);
    Lab* get_lab(std::string id);
    Component* get_component(std::string id);
    Comment* get_comment(std::string id);
    RubricObject* get_rubric(std::string id);
    RubricSection* get_rubricsection(std::string id);


    std::vector<Year*> get_years();
    std::vector<Semester*> get_semesters();
    std::vector<Class*> get_classes();
    std::vector<Comment*> get_comments();



};

//callback methods for the databases

int cb_select_all_years(void  *data,
                          int    argc,
                          char **argv,
                          char **azColName);

int cb_select_all_semesters(void  *data,
                          int    argc,
                          char **argv,
                          char **azColName);

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

int cb_select_all_components(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

int cb_select_all_commentss(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

int cb_select_all_rubrics(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

int cb_select_all_rubricsections(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

#endif // CONTROLLER_H

#ifndef LAB_H
#define LAB_H

#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"
#include "student.h"
#include "comment.h"
#include "component.h"
#include "commentengine.h"
#include "comment.h"
#include "rubricobject.h"


/**
The Lab class is an object representation of a container to hold components.
@author Luis Lopez-Bonilla
@version 1.0 (April 25 2017)
*/
using namespace std;
class Student;
class Component;
class Comment;

class Lab : public DBTable{
private:
    vector<vector<string>> javaFiles;
    vector<Component*> components;
    vector<Comment*> comments;
    vector<Comment> myComments;
    std::string labNum;
    int grade=100;
    std::string labName;
    std::string id;
    std::string studentID;
    std::string graded;
    Student *belongs = nullptr; //student pointer of whose lab it is.
    RubricObject *rubric = nullptr;


public:
    Lab(string labID, std::string studentID, string labName, string labNumber,string graded,  DBTool *tool, std::string table);
    ~Lab();

    std::string get_lab_name();
    string get_lab_num();

    void add_component(Component* com);
    void add_rubric(RubricObject* rub);
    void add_comment(Comment* com);
    void add_java_line(vector<string>);
    void set_graded(std::string booli);
    std::string get_graded();
    double get_grade();


    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(string id, string studentid, std::string labname, std::string labnumber, std::string graded);
    void set_grade(int gradetotal);

    //Allie
    map<int, Comment> commentMap;

    Comment* get_comment_at(std::string lineNo);
    Comment *get_comment_at(int lineNo);

    bool is_comment_at(int i);

    int get_no_lines_in_class(int i);
    int get_number_of_classes();
    int get_size();

    void add_comments(Comment c);
    void create_comment(string commentText, string rubricSection, double pointsDeducted, string highlightColor);

    vector<Comment> get_comment_vector();
    vector<vector<string>> get_class_code_vector();
    vector<Component*> get_components();
    vector<string> get_line_vector();

    RubricObject* get_rubric();
   // RubricObject* rubric;

    string get_section_at(int i);
    string get_section_text_at(int i);
    string get_color_at(int i);
};

int cb_add_row_lab(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);

#endif // LAB_H

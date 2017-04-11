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


using namespace std;
class Student;
class Component;
class Comment;

class Lab : public DBTable{
private:
    vector<string> javaText;
    vector<Component*> coms;
    vector<Comment*> comments;
    std::string labNum;
    int grade;
    std::string labName;
    std::string id;
    std::string studentID;
    Student *belongs = nullptr; //student pointer of whose lab it is.

    //Allie
    vector<vector<string>> classes;
     map<int, CommentEngine> commentMap;

public:
    Lab(string labID, std::string studentID, string labName, string labNumber, vector<string> aJavaText, DBTool *tool, std::string table);
    ~Lab();

    std::string get_lab_name;
    int get_lab_num();

    void add_component(Component* com);
    void add_comment(Comment* com);


    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(string id, string studentid, std::string labname, std::string labnumber);
    void set_grade(int);
    int get_grade();

    //Allie
    CommentEngine get_comment_at(int lineNo);
    bool is_comment_at(int i);
    int get_no_lines_in_class(int i);
    int get_number_of_classes();
    vector<vector<string>> get_class_code_vector();
    void add_comments(CommentEngine c);
    vector<string> get_line_vector();
    vector<string> get_java_text();


};

int cb_add_row_lab(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);

#endif // LAB_H

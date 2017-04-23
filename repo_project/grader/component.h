#ifndef COMPONENT_H
#define COMPONENT_H
#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"
#include "comment.h"

class Comment;
class Component : public DBTable
{

private:
    std::string text;
    std::string labID;
    std::string id;
    std::vector<std::string> text_lines;
    std::vector<Comment*> comments;



    std::string name;

public:
    Component(std::string id, std::string labID, std::string text, DBTool *tool, std::string table);
    ~Component();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(std::string id, std::string labid, std::string compath);

    std::string get_text();

    void make_text_lines();
    std::vector<std::string> get_text_lines();

    std::string get_id();

    void add_comment(Comment *c);
    std::vector<Comment*> get_comments();

    std::string get_name();

};

int cb_add_row_component(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);

#endif // COMPONENT_H

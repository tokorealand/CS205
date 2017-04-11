#ifndef COMMENT_H
#define COMMENT_H
#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"
#include "lab.h"

class Lab;

class Comment : public DBTable
{
private:
    Lab* inlab;
    std::string id;
    std::string labid;
    std::string linenumber;
    std::string commentphrase;
    std::string rubricsection;
    std::string highlight;
    std::string points;



public: 
    Comment(std::string id, std::string labID, std::string linenumber,std::string commentphrase, std::string rubricsection,std::string highlight,std::string points, DBTool *tool, std::string table);

~Comment();
    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

     bool add_row(std::string id, std::string labID, std::string linenumber, std::string commentphrase, std::string rubricsection, std::string highlight, std::string points);

     std::string get_comment_text();
     std::string get_rubric_section();
     double get_points_deducted();
     std::string get_highlight_color();

};

int cb_add_row_comment_ne(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);


#endif // COMMENT_H

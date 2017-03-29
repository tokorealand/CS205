#ifndef COMMENTENGINE_H
#define COMMENTENGINE_H
#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"



class CommentEngine : public DBTable
{
public:
    CommentEngine(DBTool *tool, std::string table);
    ~CommentEngine();
    void add_comment(std::string comment);
    void remove_comment(int id);
    std::string get_comment(int id);

protected:
    std::string sql_select_all_comments;

private:
    bool select_all_comments();
    bool drop_comment_table();
    std::vector<std::string> comment_list;
    std::string table_comment;
    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(int id, std::string comment);
    void repopulate();



};

int cb_add_row_comment(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName);

int cb_select_all_comments(void  *data,
               int    argc,
               char **argv,
               char **azColName);

#endif // COMMENTENGINE_H

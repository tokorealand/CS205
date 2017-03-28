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
    std::string sql_select_all;

private:
    std::vector<std::string> comment_list;



};

#endif // COMMENTENGINE_H

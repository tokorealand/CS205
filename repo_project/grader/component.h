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

class Component : public DBTable
{

private:
    std::string compath;
    std::string labID;
    std::string id;

public:
    Component(std::string id, std::string labID, std::string compath, DBTool *tool, std::string table);
    ~Component();

    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(std::string id, std::string labid, std::string compath);


};

int cb_add_row_component(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);

#endif // COMPONENT_H

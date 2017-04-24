#ifndef RUBRICSECTION_H
#define RUBRICSECTION_H


#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtool.h"
#include "dbtable.h"


class RubricSection : public DBTable
{
private:
    std::string id;
    std::string rubricid;
    std::string description;
    std::string points;
    std::string color;




public:
    RubricSection(std::string id, std::string rubricid, std::string description, std::string points, std::string color, DBTool *tool, std::string table);


    ~RubricSection();

    std::string get_id();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();
    bool add_row(std::string id, std::string rubricid, std::string description, std::string points, std::string color);

    std::string get_points();
    std::string get_color();
    std::string get_description();


};




int cb_add_row_rubricsection(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);
#endif // RUBRICSECTION_H

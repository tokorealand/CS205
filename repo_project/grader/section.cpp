#include "section.h"
#include "student.h"
#include "lab.h"
#include <iostream>

class Student;
class Lab;


Section::Section( std::string sectionID,std::string classID,DBTool *tool, std::string table):DBTable(tool, table)
{
    this->id = sectionID;
    this->classID = classID;
    this->tool = tool;


    this->name = id.substr(0, id.find("_"));

    //  repopulate();

    // Load SQL specific to child class.

    store_add_row_sql();

    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    // build_table();
}

/*
 *Deletes the objects in the tables
**/
Section::~Section()
{
    build_table();
    add_row(id,classID);
}



std::string Section::get_id()
{
    return id;
}

std::vector<Student*> Section::get_students()
{
    return students;
}

std::string Section::get_name()
{
    return name;
}


/*
 *Creates students and adds them
**/
void Section::add_student(Student *student)
{
    students.push_back(student);
}


// SQL used for inputting information
void Section::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Section::store_create_sql() {


    std::cerr << "calling store_create_sql from Section\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  classid TEXT NOT NULL";

    sql_create += " );";

}


bool Section::add_row(std::string id, std::string classid) {
    int   retCode = 0;
    char *zErrMsg = 0;



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, classid )";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(classid);
    sql_add_row += "\" ";
    sql_add_row += " );";




    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_section,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL section error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}




/** Call back for adding to student table
*/
int cb_add_row_section(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Section *obj = (Section *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}

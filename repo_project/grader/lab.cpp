#ifndef LAB_CPP
#define LAB_CPP
#include "lab.h"
#include "student.h"

class Student;

Lab::Lab(Student* belongsto,std::string labname, int labnumber, DBTool *tool, std::string table):DBTable(tool,table)
{
    labNum = labnumber;
    labName = labname;
    belongs = belongsto;

    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    //  build_table();
}

Lab::~Lab()
{
    //inputs contained information to player table inside the database
//    build_table();
//    add_row(labNum,belongs->get_studentid(),belongs->get_first_name(),belongs->get_last_name(),labName);
}

// SQL used for inputting information
void Lab::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Lab::store_create_sql() {


    std::cerr << "calling store_create_sql from Lab\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  labnumber INT PRIMARY KEY NOT NULL, ";
    sql_create += "  studentid INT NOT NULL, ";
    sql_create += "  firstname TEXT NOT NULL, ";
    sql_create += "  lastname TEXT NOT NULL, ";
    sql_create += "  labname TEXT NOT NULL";
    sql_create += " );";

}

/** Adds the inputted information into the player table database.
*/
bool Lab::add_row(int labnumber, int studentid,std::string firstname, std::string lastname, std::string labname) {
    int   retCode = 0;
    char *zErrMsg = 0;
    char  tempval[128];
    char  tempval2[128];



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( labnumber, studentid, firstname, lastname, labname ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", labnumber);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval2, "%d", studentid);
    sql_add_row += tempval2;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(firstname);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(lastname);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(labname);
    sql_add_row += "\" ";
    sql_add_row += " );";



    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_lab,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL lab error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to lab table
*/
int cb_add_row_lab(void  *data,
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

    Student *obj = (Student *) data;

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




#endif // LAB_CPP

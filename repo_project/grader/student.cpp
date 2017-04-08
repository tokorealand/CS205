#include "student.h"



Student::Student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->firstName = firstname;
    this->lastName  = lastname;
    this->sectionID = sectionID;
    this->id = studentID;

    // Load SQL specific to child class.

    store_add_row_sql();

    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}


Student::~Student()
{
    //inputs contained information to student table inside the database
    build_table();
    add_row(id,sectionID,firstName,lastName);
}



void Student::add_lab(Lab *thelab)
{
    labs.push_back(thelab);
}

std::string Student::get_id()
{
    return id;
}

std::string Student::get_first_name()
{
    return firstName;
}

std::string Student::get_last_name()
{
    return lastName;
}

// SQL used for inputting information
void Student::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Student::store_create_sql() {


    std::cerr << "calling store_create_sql from Student\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  sectionid TEXT NOT NULL, ";
    sql_create += "  firstname TEXT NOT NULL, ";
    sql_create += "  lastname TEXT NOT NULL";
    sql_create += " );";

}

/** Adds the inputted information into the student table database.
*/
bool Student::add_row(std::string id, std::string sectionid, std::string firstname, std::string lastname) {
    int   retCode = 0;
    char *zErrMsg = 0;



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, sectionid, firstname, lastname ) ";
    sql_add_row += "VALUES (";

    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(sectionid);
     sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(firstname);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(lastname);
    sql_add_row += "\" ";
    sql_add_row += " );";



    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_student,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL student error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to student table
*/
int cb_add_row_student(void  *data,
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


#include "semester.h"

Semester::Semester(std::string id, std::string yearid,DBTool *tool, std::string table):DBTable(tool,table)
{
    this->id=id;
    this->yearid=yearid;
    this->tool=tool;
    this->name = id.substr(0, id.find("_"));
    build_table();
    store_add_row_sql();
    store_create_sql();
}


/**
Destructor for Semester which adds itself to the database.
*/
Semester::~Semester()
{


    build_table();
    add_row(id,yearid);
}

std::string Semester:: get_id()
{
    return id;
}

/**
Adds class to the class vector in class.
@param Class - cla
*/
void Semester::add_class(Class* cla)
{
classes.push_back(cla);
}


std::vector<Class*> Semester::get_classes()
{
    return classes;
}

std::string Semester:: get_name()
{
    return this->name;
}

// SQL used for inputting information
void Semester::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Semester::store_create_sql() {


   // std::cerr << "calling store_create_sql from Class\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  yearid TEXT NOT NULL";

    sql_create += " );";

}

/**
 * @brief SQL method for how to add row to class table in database.
 * @param id
 * @param yearid
 * @return
 */
bool Semester::add_row(std::string id, std::string yearid) {
    int   retCode = 0;
    char *zErrMsg = 0;



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, yearid )";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(yearid);
    sql_add_row += "\" ";
    sql_add_row += " );";




    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_semester,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL semester error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to semester table
*/
int cb_add_row_semester(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName)
{



   // std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Semester *obj = (Semester *) data;

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

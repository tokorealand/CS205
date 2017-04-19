#include "year.h"

Year::Year(std::string id, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->id=id;
    this->tool=tool;
    store_add_row_sql();
    store_create_sql();
}


Year::~Year()
{


    build_table();
    add_row(id);
}

std::string Year:: get_id()
{
    return id;
}

void Year::add_semester(Semester* sem)
{
semester.push_back(sem);
}

std::vector<Semester*> Year::get_semesters()
{
    return semester;
}

// SQL used for inputting information
void Year::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Year::store_create_sql() {


    std::cerr << "calling store_create_sql from Class\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL";

    sql_create += " );";

}

bool Year::add_row(std::string id) {
    int   retCode = 0;
    char *zErrMsg = 0;



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id )";
    sql_add_row += "VALUES (";




    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\" ";
    sql_add_row += " );";




    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_year,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL year error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to student table
*/
int cb_add_row_year(void  *data,
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

    Year *obj = (Year *) data;

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

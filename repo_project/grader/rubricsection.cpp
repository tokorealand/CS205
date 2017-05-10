#include "rubricsection.h"

RubricSection::RubricSection(std::string id, std::string rubricid, std::string description, std::string points, std::string color, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->id=id;
    this->rubricid=rubricid;
    this->description=description;
    this->points=points;
    this->color=color;
    this->deleted = false;

    store_add_row_sql();
    store_create_sql();

}

/**
Destructor for rubricsection which adds itself to the database.
*/
RubricSection::~RubricSection()
{
    if(deleted==false)
    {
    build_table();
    add_row(id,rubricid,description,points,color);
    }
}

std::string RubricSection::get_id()
{
    return id;
}

std::string RubricSection:: get_points()
{
    return points;
}

std::string RubricSection:: get_color()
{
    return color;
}

void RubricSection::set_deleted()
{
    deleted = true;
}

std::string RubricSection:: get_description()
{
    return description;
}

// SQL used for inputting information
void RubricSection::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void RubricSection::store_create_sql() {


    std::cerr << "calling store_create_sql from RubricObject\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  rubricid TEXT NOT NULL, ";
    sql_create += "  name TEXT NOT NULL, ";
    sql_create += "  points TEXT NOT NULL, ";
    sql_create += "  color TEXT NOT NULL";
    sql_create += " );";

}

/**
 * @brief SQL method for how to add row to class table in database.
 * @param id
 * @param rubricid
 * @param description
 * @param points
 * @param color
 * @return
 */
bool RubricSection::add_row(std::string id, std::string rubricid, std::string description, std::string points, std::string color) {
    int   retCode = 0;
    char *zErrMsg = 0;




    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, rubricid, name, points, color ) ";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(rubricid);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(description);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(points);
    sql_add_row += "\", ";


    sql_add_row += "\"";
    sql_add_row += std::string(color);
    sql_add_row += "\" ";
    sql_add_row += " );";



    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_rubricsection,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL RS error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to rubricsection table
*/
int cb_add_row_rubricsection(void  *data,
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

    RubricSection *obj = (RubricSection *) data;

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

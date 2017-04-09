#include "class.h"

Class::Class(std::string classID, int number_of_sections, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->number_of_sections = number_of_sections;
    this->id = classID;
    this->tool = tool;

    store_add_row_sql();

    store_create_sql();
}


Class::~Class()
{


    build_table();
    add_row(id,number_of_sections);
}

std::string Class:: get_id()
{
    return id;
}


///*

/*
 *Creates sections and adds them
**/
void Class::add_section(Section* sec)
{
sections.push_back(sec);
}



Section* Class::get_section(int sectionid)
{/*
    Section *s;
    for(std::vector<Section*>::iterator it = sections.begin();
        it != sections.end(); ++it)
    {
        s = (*it);
        if(s->get_id() == sectionid)
        {
            return s;
        }*/
    //  }
    return NULL;
}




// SQL used for inputting information
void Class::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Class::store_create_sql() {


    std::cerr << "calling store_create_sql from Section\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  number_of_sections INT NOT NULL";

    sql_create += " );";

}


bool Class::add_row(std::string id, int number_of_sections) {
    int   retCode = 0;
    char *zErrMsg = 0;
    char  tempval[128];



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, number_of_sections )";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", number_of_sections);
    sql_add_row += tempval;
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
int cb_add_row_class(void  *data,
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

    Class *obj = (Class *) data;

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

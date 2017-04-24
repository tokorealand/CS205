#include "comment.h"

Comment::Comment(std::string id, std::string componentID, std::string linenumber, std::string commentphrase, std::string rubricsection, std::string highlight, std::string points, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->id = id;
    this->componentID = componentID;
    this->linenumber = linenumber;
    this->commentphrase = commentphrase;
    this->rubricsection = rubricsection;
    this->highlight = highlight;
    this->points = points;
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();
}

Comment::~Comment(){
    build_table( );
    std::cout<<"addas";
    add_row(id,  componentID,  linenumber, commentphrase,  rubricsection, highlight, points);
}

std::string Comment::get_id(){
    return id;
}

string Comment::get_comment_text(){
    return commentphrase;
}

string Comment::get_rubric_section(){
    return rubricsection;
}

double Comment::get_points_deducted(){
    return std::stod(points);
}

string Comment::get_highlight_color(){
    return highlight;
}

string Comment::get_section_color(){
    return "";
}

string Comment::get_linenumber(){
    return linenumber;
}


// SQL used for inputting information
void Comment::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Comment::store_create_sql() {


    std::cerr << "calling store_create_sql from Comment\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  componentid TEXT NOT NULL, ";
    sql_create += "  linenumber TEXT NOT NULL, ";
    sql_create += "  commentphrase TEXT NOT NULL, ";
    sql_create += "  rubricsection TEXT NOT NULL, ";
    sql_create += "  highlight TEXT NOT NULL, ";
    sql_create += "  points TEXT NOT NULL";
    sql_create += " );";

}

/** Adds the inputted information into the component table database.
*/
bool Comment::add_row(std::string id, std::string componentid, std::string linenumber,std::string commentphrase, std::string rubricsection,std::string highlight, std::string points) {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, componentid, linenumber, commentphrase, rubricsection, highlight ) ";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(componentid);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(linenumber);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(commentphrase);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(rubricsection);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(highlight);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(points);
    sql_add_row += "\" ";
    sql_add_row += " );";



    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_component,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL comment error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to comment table
*/
int cb_add_row_comment_ne(void  *data,
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

    Comment *obj = (Comment *) data;

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

bool Comment::get_highlight(){
    if (highlight != ""){
        return true;
    }
    return false;
}



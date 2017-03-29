#include "commentengine.h"

CommentEngine::CommentEngine(DBTool *tool, std::string table):DBTable(tool,table)
{
    // Load SQL specific to child class.
    table_comment=table;
    store_add_row_sql();

    store_create_sql();

    repopulate();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

CommentEngine::~CommentEngine()
{
    //inputs contained information to player table inside the database
    build_table();
    int id=0;
    for(std::vector<std::string>::iterator it = comment_list.begin();
        it != comment_list.end(); ++it)
    {
        add_row(id,*it);
        id++;
    }
}

void CommentEngine::add_comment(std::string comment)
{

    comment_list.push_back(comment);
}

void CommentEngine::repopulate()
{
    select_all_comments();
    drop_comment_table();
}

void CommentEngine::remove_comment(int id)
{
    comment_list.erase(comment_list.begin()+id);
}

std::string CommentEngine::get_comment(int id)
{
return comment_list.at(id);
}

void CommentEngine::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

//Used to retriveve all players in database
bool CommentEngine::select_all_comments() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_comments  = "SELECT * FROM ";
    sql_select_all_comments += table_comment;
    sql_select_all_comments += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_comments.c_str(),
                           cb_select_all_comments,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        //        std::cerr << table_name
        //                  << " template ::"
        //                  << std::endl
        //                  << "SQL error: "
        //                  << zErrMsg;

        //        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// SQL used to create the table in the database.
void CommentEngine::store_create_sql() {


    std::cerr << "calling store_create_sql from Comment\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT NOT NULL, ";
    sql_create += "  comment TEXT NOT NULL";
    sql_create += " );";

}

// Removes the db table from the database.
bool CommentEngine::drop_comment_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_comment="DROP TABLE ";
    sql_drop_comment+=table_comment;
    sql_drop_comment+=";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_comment.c_str(),
                           cb_drop,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if( retCode != SQLITE_OK ){

        //        std::cerr << sql_drop
        //                  << std::endl;

        //        std::cerr << "SQL error: "
        //                  << zErrMsg
        //                  << std::endl;

        //        sqlite3_free(zErrMsg);
    }


    return retCode;
}

bool CommentEngine::add_row(int id, std::string comment) {
    int   retCode = 0;
    char *zErrMsg = 0;
    char  tempval[128];


    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, comment ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(comment);
    sql_add_row += "\" ";
    sql_add_row += " );";



    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_comment,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL edrror: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to student table
*/
int cb_add_row_comment(void  *data,
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

    CommentEngine *obj = (CommentEngine *) data;


    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}

//Call back for select_all_pgh
int cb_select_all_comments(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName)
{



    std::cerr << "cb_select_all_comments being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    CommentEngine *obj = (CommentEngine *) data;


    for(i = 0; i < argc; i++){
        //        std::cout << azColName[i]
        //                  << " = "
        //                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
        //                  << std::endl;



    }
    obj->add_comment(argv[1]);
    //old from lab 6

    return 0;
}



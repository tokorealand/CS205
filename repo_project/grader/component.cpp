#include "component.h"

Component::Component(std::string id, std::string labID, std::string aText, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->id = id;
    this->labID = labID;
    this->text = aText;
    this->name = id.substr(0, id.find("_"));
    make_text_lines();



    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();



}

/**
Destructor for Class which adds itself to the database.
*/
Component::~Component()
{

    build_table();
    add_row(id,labID,text);
}

std::string Component::get_id()
{
    return id;
}

std::string Component:: get_text()
{
    return text;
}

void Component:: make_text_lines()
{
    int parseStart = 0;
    int parseEnd = text.find("\n");
    int parseLen= parseEnd - parseStart;
    while(text.find("\n", parseStart) != text.npos)
    {
        std:: string line = text.substr(parseStart, parseLen);
        text_lines.push_back(line);       
        parseStart = parseEnd+1;
        parseEnd = text.find("\n", parseStart) ;
        parseLen =  parseEnd - parseStart;
    }
}

std::vector<std::string> Component:: get_text_lines()
{
    return this->text_lines;
}

void Component::add_comment(Comment *c){
    comments.push_back(c);
}

std::vector<Comment*> Component::get_comments()
{
    return comments;
}

std::string Component::get_name()
{
    return name;
}

int Component::get_points()
{
    int total = 0;

    for(int i = 0; i < comments.size(); i ++)
    {
        if(comments.at(i)->get_deleted() ==false)
        {
            total = total+comments.at(i)->get_points();
        }
    }
    return total;
}


// SQL used for inputting information
void Component::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Component::store_create_sql() {


    std::cerr << "calling store_create_sql from Component\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  labid TEXT NOT NULL, ";
    sql_create += "  text TEXT NOT NULL";
    sql_create += " );";

}

/**
 * @brief SQL method for how to add row to class table in database.
 * @param id
 * @param labid
 * @param text
 * @return
 */
bool Component::add_row(std::string id, std::string labid, std::string text) {
    int   retCode = 0;
    char *zErrMsg = 0;




    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, labid, text ) ";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(labid);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(text);
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
                  << "SQL component error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to component table
*/
int cb_add_row_component(void  *data,
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

    Component *obj = (Component *) data;

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

bool Component::is_comment_at(int lineNo){

    //go through all the comments
    for(int i = 0; i < comments.size(); i++){

        //check if the line numbers match
        if(comments.at(i)->get_linenumber() == to_string(lineNo)){
            return true; //if so, return true
        }
    }
    return false;
}

//use this method to get the comment at a particular line number
Comment* Component::get_comment_at(int lineNo){

    for(int i = 0; i < comments.size(); i++){
        if(comments.at(i)->get_linenumber() == to_string(lineNo)){
            return comments.at(i);
        }
    }
    return nullptr;
}

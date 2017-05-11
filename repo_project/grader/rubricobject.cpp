#include "rubricobject.h"
#include <iostream>

using namespace std;

RubricObject::RubricObject(string id, string classID, DBTool *tool, string table):DBTable(tool,table){
    this->id=id;
    this->classid=classID;
    this->name ="Rubric_"+id.substr(0, id.find("_"));
    this->tool=tool;
    this->table=table;
    this->deleted = false;
    build_table();
    store_add_row_sql();
    store_create_sql();
}

void RubricObject::operator = (RubricObject &obj) {
    this->rubricSections = obj.rubricSections;

}

/**
Destructor for RubricObject which adds itself to the database.
*/
RubricObject::~RubricObject()
{
    if(deleted==false)
    {
    build_table();
    add_row(id,classid);
    }
}

//getters
vector<RubricSection*> RubricObject::get_rubric_sections(){
    return rubricSections;
}

string RubricObject:: get_name()
{
    return name;
}

//setters
void RubricObject::add_rubric_section(RubricSection *rsec){
    rubricSections.push_back(rsec);
    total+=std::stoi(rsec->get_points());
}

std::string RubricObject::get_id()
{
    return id;
}

void RubricObject::set_deleted()
{
    deleted = true;
}
std::string RubricObject::get_class_id()
{
    return classid;
}
int RubricObject::get_total_points()
{
    return total;
}

bool RubricObject::get_deleted()
{
    return deleted;
}



int RubricObject::get_size(){
    cout << "size " + size << endl;
    return size;
}

// SQL used for inputting information
void RubricObject::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void RubricObject::store_create_sql() {


  //  std::cerr << "calling store_create_sql from RubricObject\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  classid TEXT NOT NULL";
    sql_create += " );";

}

/**
 * @brief SQL method for how to add row to class table in database.
 * @param id
 * @param classid
 * @return
 */
bool RubricObject::add_row(std::string id, std::string classid) {
    int   retCode = 0;
    char *zErrMsg = 0;




    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, classid ) ";
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
                           cb_add_row_rubric,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL RO error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to rubric table
*/
int cb_add_row_rubric(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName)
{



    //std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    RubricObject *obj = (RubricObject *) data;

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



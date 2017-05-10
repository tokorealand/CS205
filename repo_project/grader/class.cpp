#include "class.h"

Class::Class(std::string classID, string semesterid, DBTool *tool, std::string table):DBTable(tool,table)
{

    this->id = classID;
    this->tool = tool;
    this->semesterid=semesterid;
    this->name = id.substr(0, id.find("_"));

    store_add_row_sql();

    store_create_sql();
}

/**
Destructor for Class which adds itself to the database.
*/
Class::~Class()
{


    build_table();
    add_row(id,semesterid);
}

std::string Class:: get_id()
{
    return id;
}



/**
Adds section to the section vector in class.
@param Section - sec
*/

void Class::add_section(Section* sec)
{
    sections.push_back(sec);
}

/**
Adds lab to the lab vector in class.
@param Lab - lab
*/
void Class::add_lab(Lab* lab)
{
    labs.push_back(lab);
}

/**
Counts the labs matching the given lab number.
@param string - labnum
@returns int - number of labs matching
*/
int Class:: count_lab_matching_key(string labnum)
{
    int count=0;


    for(Lab* lb : labs)
    {
        if(lb->get_lab_num()==labnum)
        {
            count++;
        }
    }
    return count;
}

/**
Checks if all labs matching the given key are graded.
@param string - labnum
@returns bool - true if all graded, otherwise false
*/
bool Class:: check_all_matching_key_graded(string labnum)
{


    for(Lab* lb : labs)
    {
        if(lb->get_lab_num()==labnum)
        {
            if(lb->get_graded() == "0")
            {
                return false;
            }
        }
    }

    return true;
}

/**
Calculates the percentage of the labs matching the given lab number that are graded.
@param string - labnum
@returns double - percentage of labs graded
*/
double Class:: get_amount_graded(string labnum)
{
    double count =0;
    double totallabs =0;
    for(Lab* lb : labs)
    {
        if(lb->get_lab_num()==labnum)
        {
            totallabs++;
            if(lb->get_graded() == "1")
            {
                count++;
            }
        }
    }
    return (count/totallabs)*100;


}



std::string Class:: get_name()
{
    return this->name;
}

std::vector<Section*> Class::get_sections()
{
    return sections;
}

vector<RubricObject*> Class::get_rubrics()
{
    return rubrics;
}


/**
Adds rubric to the rubric vector in class.
@param RubricObject - rubric
*/
void Class:: add_rubric(RubricObject* rubric)
{
    rubrics.push_back(rubric);
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


    std::cerr << "calling store_create_sql from Class\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  semesterid TEXT NOT NULL";

    sql_create += " );";


}


/**
 * @brief SQL method for how to add row to class table in database.
 * @param id
 * @param semesterid
 * @return
 */
bool Class::add_row(std::string id, std::string semesterid) {
    int   retCode = 0;
    char *zErrMsg = 0;



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, semesterid )";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(semesterid);
    sql_add_row += "\" ";
    sql_add_row += " );";




    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_class,
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

/** Call back for adding to class table
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



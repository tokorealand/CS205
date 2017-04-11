#ifndef LAB_CPP
#define LAB_CPP
#include "lab.h"
#include "student.h"

class Student;

Lab::Lab(std::string labID, string studentID, string labName, string labNumber, vector<string> aJavaText, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->javaText = aJavaText;
    this->id = labID;
    this->studentID = studentID;
    this->labName = labName;
    this->labNum = labNumber;
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    //  build_table();
}

Lab::~Lab()
{
    //inputs contained information to player table inside the database
    build_table();
    add_row(id,studentID,labName,labNum);
}

std::string Lab::get_id()
{
    return id;
}

void Lab::add_component(Component *com)
{
    coms.push_back(com);
}

// SQL used for inputting information
void Lab::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Lab::store_create_sql() {


    std::cerr << "calling store_create_sql from Lab\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  studentid TEXT NOT NULL, ";
    sql_create += "  labname TEXT NOT NULL, ";
    sql_create += "  labnumber TEXT NOT NULL";
    sql_create += " );";

}

/** Adds the inputted information into the player table database.
*/
bool Lab::add_row(std::string id, std::string studentid, std::string labname , std::string labnumber) {
    int   retCode = 0;
    char *zErrMsg = 0;




    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, studentid, labname, labnumber ) ";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(studentid);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(labname);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(labnumber);
    sql_add_row += "\" ";
    sql_add_row += " );";



    // std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_lab,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL lab error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/** Call back for adding to lab table
*/
int cb_add_row_lab(void  *data,
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

//METHODS ALLIE MADE FOR THE EXPORT ENGINE
vector<string> Lab::get_line_vector(){

    vector<string> temp;

    //create line by line vector -- this would be in the file parser. in this case we would be reading the file line by line and placing each line in a vector
    temp.push_back("first line text");
    temp.push_back("second line text");
    temp.push_back("third line text");
    temp.push_back("fourth line text");

    return temp;
}


//add an already created comment
void Lab::add_comments(CommentEngine c){
    //commentMap.insert(make_pair(1,c));
}

//returns the vector representing each class - a vector of strings representing each line of code
vector<vector<string>> Lab::get_class_code_vector(){
    return classes;
}

int Lab::get_number_of_classes(){
    return 0;
}

//get class in location i, find the size of the vector containing each line of the code as a string
int Lab::get_no_lines_in_class(int i){
    return classes.at(i).size();
}
//check if there is a comment at a given line number
bool Lab::is_comment_at(int i){
    if(commentMap.find(i) == commentMap.end()){
        return false;
    }else{
        return true;
    }
}

//use this method to get the comment at a particular line number
CommentEngine Lab::get_comment_at(int lineNo){
    return commentMap.at(lineNo);
}

vector<string> Lab ::get_java_text()
{
    return javaText;
}



#endif // LAB_CPP

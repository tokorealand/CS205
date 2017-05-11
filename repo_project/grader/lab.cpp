#ifndef LAB_CPP
#define LAB_CPP

#include "lab.h"
#include "string"

using namespace std;

class Student;

Lab::Lab(std::string labID, string studentID, string labName, string labNumber, string graded, DBTool *tool, std::string table):DBTable(tool,table)
{

    this->id = labID;
    this->studentID = studentID;
    this->labName = labName;
    this->labNum = labNumber;
    this->graded=graded;
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    //  build_table();
}

/**
Destructor for Class which adds itself to the database.
*/
Lab::~Lab()
{
    //inputs contained information to player table inside the database
    build_table();
    add_row(id,studentID,labName,labNum,graded);
}

/**
Adds rubric to the rubric vector in class.
@param RubricObject - rub
*/
void Lab::add_rubric(RubricObject *rub)
{
    this->rubric=rub;
}

std::string Lab::get_id(){
    return id;
}

/**
Adds component to the component vector in class.
@param Component - com
*/
void Lab::add_component(Component *com){
    components.push_back(com);
}

/**
Adds comment to the comment vector in class.
@param Comment - com
*/
void Lab::add_comment(Comment *com){
    comments.push_back(com);
}

// SQL used for inputting information
void Lab::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

void Lab::set_graded(std::string booli)
{
graded=booli;
}

std::string Lab::get_graded()
{
return graded;
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
    sql_create += "  labnumber TEXT NOT NULL, ";
    sql_create += "  graded TEXT NOT NULL";
    sql_create += " );";

}

/**
 * @brief SQL method for how to add row to class table in database.
 * @param id
 * @param studentid
 * @param labname
 * @param labnumber
 * @param graded
 * @return
 */
bool Lab::add_row(std::string id, std::string studentid, std::string labname , std::string labnumber, std::string graded) {
    int   retCode = 0;
    char *zErrMsg = 0;




    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, studentid, labname, labnumber, graded ) ";
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
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(graded);
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

    Lab *obj = (Lab *) data;

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
void Lab::add_comments(Comment c){
    //commentMap.insert(make_pair(1,c));
}

//returns the vector representing each class - a vector of strings representing each line of code
vector<vector<string>> Lab::get_class_code_vector(){
    return javaFiles;
}

int Lab::get_number_of_classes(){
    return 0;
}

void Lab:: add_java_line(vector<string> javaLine){
    javaFiles.push_back(javaLine);
}

//get class in location i, find the size of the vector containing each line of the code as a string
int Lab::get_no_lines_in_class(int i){
    return javaFiles.at(i).size();
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
Comment* Lab::get_comment_at(std::string lineNo){
    return comments.at(std::stoi(lineNo));
}

//same as above but with an int -- ALLIE
Comment* Lab::get_comment_at(int lineNo){
    return comments.at(lineNo);
}

vector<Comment> Lab::get_comment_vector(){
    return myComments;
}

std::string Lab::get_lab_name(){
    return labName;
}
void Lab::set_grade(int gradetotal)
{
    grade = gradetotal;
}

vector<Component*> Lab:: get_components()
{
    return components;
}

RubricObject *Lab::get_rubric(){
    return rubric;
}

std::string Lab::get_lab_num()
{
    return labNum;
}

double Lab::get_grade()
{
    double total =grade;
    for(int i = 0; i < components.size(); i++)
    {
       total = total - components.at(i)->get_points();
    }
    return (total/(double)grade)*100;
}


#endif // LAB_CPP

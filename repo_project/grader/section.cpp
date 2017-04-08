#include "section.h"
#include "student.h"
#include "lab.h"
#include <iostream>

class Student;
class Lab;


Section::Section( std::string sectionID,std::string classID,DBTool *tool, std::string table):DBTable(tool, table)
{
    this->id = sectionID;
    this->classID = classID;
    this->tool = tool;

  //  repopulate();

    // Load SQL specific to child class.

    store_add_row_sql();

    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
   // build_table();
}

/*
 *Deletes the objects in the tables
**/
Section::~Section()
{


    build_table();
    add_row(id,classID);

}

///*
// *Creates objects from the database
//**/
//void Section::repopulate()
//{

//    select_all_students_in_section();
//    drop_student_table();
//    select_all_labs_in_section();
//    drop_lab_table();
//}

//void Section::increment_student()
//{
//    ++*studentcounter;
//}


std::string Section::get_id()
{
    return id;
}

bool Section::check_for_student(std::string studentid)
{
//    Student *p;


//    for(std::vector<Student*>::iterator it = students.begin();
//        it != students.end(); ++it)
//    {
//        p = *it;

//        if(p->get_studentid() == studentid)
//        {
//            return true;
//        }
//    }
//    return false;
}
/*
 *Creates students and adds them
**/
void Section::add_student(Student *student)
{


        students.push_back(student);

}

///*
// *Creates students and adds them
//**/
//void Section::add_student_db(string fn, string ln)
//{
//    std::cout<<*studentcounter<<"ddddddd";
//    if(get_student(fn,ln) == NULL)
//    {
//        Student *std = new Student(studentcounter,labcounter,id,fn,ln,tool,table_students);
//        students.push_back(std);
//    }
//}
///*
// *Creates lab and adds it to student only if student exists
//**/
//void Section::add_lab_student(string fn, string ln, string labname, int labnumber)
//{
//    Student *p;


//    for(std::vector<Student*>::iterator it = students.begin();
//        it != students.end(); ++it)
//    {
//        p = *it;

//        if(p -> get_first_name() == fn && p -> get_last_name() == ln)
//        {

//            Lab* g = new Lab(p,labname,labnumber,tool,table_labs);

//            p -> add_lab(g);
//            labs.push_back(g);
//            return;
//        }

//    }
//    std::cout<<"Student: "<<fn<<" "<<ln<<" does not exists.";

//}


///*
// *Creates lab and adds it to student only if student exists
//**/
//void Section::add_lab_student(string fn, string ln, string labname)
//{
//    Student *p;


//    for(std::vector<Student*>::iterator it = students.begin();
//        it != students.end(); ++it)
//    {
//        p = *it;

//        if(p -> get_first_name() == fn && p -> get_last_name() == ln)
//        {

//            Lab* g = new Lab(p,labname,*labcounter,tool,table_labs);

//            p -> add_lab(g);
//            labs.push_back(g);
//            return;
//        }

//    }
//    std::cout<<"Student: "<<fn<<" "<<ln<<" does not exists.";

//}

//Student* Section::get_student(std::string fn, std::string ln)
//{
//    Student *p;
//    for(std::vector<Student*>::iterator it = students.begin();
//        it != students.end(); ++it)
//    {
//        p = *it;

//        if(p -> get_first_name() == fn && p -> get_last_name() == ln)
//        {
//            return p;
//        }

//    }
//    std::cout<<"Student: "<<fn<<" "<<ln<<" does not exists.";

//    return NULL;
//}

// SQL used for inputting information
void Section::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

// SQL used to create the table in the database.
void Section::store_create_sql() {


    std::cerr << "calling store_create_sql from Section\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  classid TEXT NOT NULL";

    sql_create += " );";

}


bool Section::add_row(std::string id, std::string classid) {
    int   retCode = 0;
    char *zErrMsg = 0;



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, classid )";
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
////Used to retriveve all students in database
//bool Section::select_all_students_in_section() {
//    int   retCode = 0;
//    char *zErrMsg = 0;

//    sql_select_all_students_in_section  = "SELECT * FROM ";
//    sql_select_all_students_in_section += table_students;
//    sql_select_all_students_in_section += ";";

//    retCode = sqlite3_exec(curr_db->db_ref(),
//                           sql_select_all_students_in_section.c_str(),
//                           cb_select_all_students_in_section,
//                           this,
//                           &zErrMsg          );

//    if( retCode != SQLITE_OK ){

//        //        std::cerr << table_name
//        //                  << " template ::"
//        //                  << std::endl
//        //                  << "SQL error: "
//        //                  << zErrMsg;

//        //        sqlite3_free(zErrMsg);
//    }

//    return retCode;
//}


//// Removes the db table from the database.
//bool Section::drop_student_table() {

//    // Initialize local variables.
//    int   retCode = 0;
//    char *zErrMsg = 0;
//    std::string sql_drop_student="DROP TABLE ";
//    sql_drop_student+=table_students;
//    sql_drop_student+=";";


//    // Call sqlite to run the SQL call using the
//    // callback to store any results.
//    retCode = sqlite3_exec(curr_db->db_ref(),
//                           sql_drop_student.c_str(),
//                           cb_drop,
//                           this,
//                           &zErrMsg          );

//    // Process a failed call.
//    if( retCode != SQLITE_OK ){

//        //        std::cerr << sql_drop
//        //                  << std::endl;

//        //        std::cerr << "SQL error: "
//        //                  << zErrMsg
//        //                  << std::endl;

//        //        sqlite3_free(zErrMsg);
//    }


//    return retCode;
//}

////Used to retrieve all labs in database
//bool Section::select_all_labs_in_section() {
//    int   retCode = 0;
//    char *zErrMsg = 0;

//    sql_select_all_labs_in_section  = "SELECT * FROM ";
//    sql_select_all_labs_in_section += table_labs;
//    sql_select_all_labs_in_section += ";";

//    retCode = sqlite3_exec(curr_db->db_ref(),
//                           sql_select_all_labs_in_section.c_str(),
//                           cb_select_all_labs_in_section,
//                           this,
//                           &zErrMsg          );

//    if( retCode != SQLITE_OK ){

//        //        std::cerr << table_name
//        //                  << " template ::"
//        //                  << std::endl
//        //                  << "SQL error: "
//        //                  << zErrMsg;

//        //        sqlite3_free(zErrMsg);
//    }

//    return retCode;
//}

//// Removes the db table from the database.
//bool Section::drop_lab_table() {

//    // Initialize local variables.
//    int   retCode = 0;
//    char *zErrMsg = 0;
//    std::string sql_drop_lab="DROP TABLE ";
//    sql_drop_lab+=table_labs;
//    sql_drop_lab+=";";


//    // Call sqlite to run the SQL call using the
//    // callback to store any results.
//    retCode = sqlite3_exec(curr_db->db_ref(),
//                           sql_drop_lab.c_str(),
//                           cb_drop,
//                           this,
//                           &zErrMsg          );

//    // Process a failed call.
//    if( retCode != SQLITE_OK ){

//        //        std::cerr << sql_drop
//        //                  << std::endl;

//        //        std::cerr << "SQL error: "
//        //                  << zErrMsg
//        //                  << std::endl;

//        //        sqlite3_free(zErrMsg);
//    }


//    return retCode;
//}

////Call back for select_all_pgh
//int cb_select_all_students_in_section(void  *data,
//                                      int    argc,
//                                      char **argv,
//                                      char **azColName)
//{



//    std::cerr << "cb_select_all_students being called\n";

//    if(argc < 1) {
//        std::cerr << "No data presented to callback "
//                  << "argc = " << argc
//                  << std::endl;
//    }

//    int i;

//    Section *obj = (Section *) data;

//    std::cout << "------------------------------\n";
//    std::cout << obj->get_name()
//              << std::endl;

//    for(i = 0; i < argc; i++){
//        //        std::cout << azColName[i]
//        //                  << " = "
//        //                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
//        //                  << std::endl;



//    }
//    int id_check = obj->get_id();
//    if(std::stoi(argv[1]) == id_check)
//    {
//        obj->increment_student();
//        std::cout<<"ooooo";
//        obj->add_student_db(argv[2],argv[3]);
//    }
//    //old from lab 6

//    return 0;
//}

////Call back for select_all_g
//int cb_select_all_labs_in_section(void  *data,
//                                  int    argc,
//                                  char **argv,
//                                  char **azColName)
//{



//    std::cerr << "cb_select_all_labs_in_section being called\n";

//    if(argc < 1) {
//        std::cerr << "No data presented to callback "
//                  << "argc = " << argc
//                  << std::endl;
//    }

//    int i;

//    Section *obj = (Section *) data;

//    std::cout << "------------------------------\n";
//    std::cout << obj->get_name()
//              << std::endl;

//    for(i = 0; i < argc; i++){
//        //        std::cout << azColName[i]
//        //                  << " = "
//        //                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
//        //                  << std::endl;



//    }


//    obj->add_lab_student(argv[1],argv[2],argv[3],std::stoi(argv[0]));
//    return 0;
//}


/** Call back for adding to student table
*/
int cb_add_row_section(void  *data,
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

    Section *obj = (Section *) data;

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

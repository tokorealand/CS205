#include "section.h"
#include "student.h"
#include "lab.h"
#include <iostream>

class Student;
class Lab;


Section::Section(int id, DBTool *tool):DBTable(tool)
{
    this->id=id;
    this->tool=tool;
    repopulate();

}

/*
 *Deletes the objects in the tables
**/
Section::~Section()
{
    for(std::vector<Lab*>::iterator it = labs.begin();
        it != labs.end(); ++it)
    {
        delete *it;
    }
    for(std::vector<Student*>::iterator it = students.begin();
        it != students.end(); ++it)
    {
        delete *it;
    }
}

/*
 *Creates objects from the database
**/
void Section::repopulate()
{

    select_all_students_in_section();
    drop_student_table();
    select_all_labs_in_section();
    drop_lab_table();
}

/*
 *Creates students and adds them
**/
void Section::add_student(string fn, string ln)
{
    if(get_student(fn,ln)==NULL)
    {
    Student *std = new Student(id,fn,ln,tool,table_students);
    students.push_back(std);
    }
}

/*
 *Creates lab and adds it to student only if student exists
**/
void Section::add_lab_student(string fn, string ln, string labname, int labnumber)
{
    Student *p;


    for(std::vector<Student*>::iterator it = students.begin();
        it != students.end(); ++it)
    {
        p = *it;

        if(p -> get_first_name() == fn && p -> get_last_name() == ln)
        {
            Lab* g = new Lab(p,labname,labnumber,tool,table_labs);

            p -> add_lab(g);
            labs.push_back(g);
            return;
        }

    }
    std::cout<<"Student: "<<fn<<" "<<ln<<" does not exists.";

}

Student* Section::get_student(std::string fn, std::string ln)
{
    Student *p;
    for(std::vector<Student*>::iterator it = students.begin();
        it != students.end(); ++it)
    {
        p = *it;

        if(p -> get_first_name() == fn && p -> get_last_name() == ln)
        {
            return p;
        }

    }
    std::cout<<"Student: "<<fn<<" "<<ln<<" does not exists.";

    return NULL;
}


//Used to retriveve all players in database
bool Section::select_all_students_in_section() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_students_in_section  = "SELECT * FROM ";
    sql_select_all_students_in_section += table_students;
    sql_select_all_students_in_section += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_students_in_section.c_str(),
                           cb_select_all_students_in_section,
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


// Removes the db table from the database.
bool Section::drop_student_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_student="DROP TABLE ";
    sql_drop_student+=table_students;
    sql_drop_student+=";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_student.c_str(),
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

//Used to retrieve all games in database
bool Section::select_all_labs_in_section() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_labs_in_section  = "SELECT * FROM ";
    sql_select_all_labs_in_section += table_labs;
    sql_select_all_labs_in_section += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_labs_in_section.c_str(),
                           cb_select_all_labs_in_section,
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

// Removes the db table from the database.
bool Section::drop_lab_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_lab="DROP TABLE ";
    sql_drop_lab+=table_labs;
    sql_drop_lab+=";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_lab.c_str(),
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

//Call back for select_all_pgh
int cb_select_all_students_in_section(void  *data,
                                      int    argc,
                                      char **argv,
                                      char **azColName)
{



    std::cerr << "cb_select_all_pgh being called\n";

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
        //        std::cout << azColName[i]
        //                  << " = "
        //                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
        //                  << std::endl;



    }
    obj->add_student(argv[0],argv[1]);
    //old from lab 6

    return 0;
}

//Call back for select_all_g
int cb_select_all_labs_in_section(void  *data,
                                  int    argc,
                                  char **argv,
                                  char **azColName)
{



    std::cerr << "cb_select_all_g being called\n";

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
        //        std::cout << azColName[i]
        //                  << " = "
        //                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
        //                  << std::endl;
        //        std::cout<<"444444"<<std::stoi(argv[3]);
        //        obj->add_gameto_player(argv[1],argv[2],argv[0],std::stoi(argv[3]));



    }

    //    obj -> add_gameto_player(argv[1],argv[2],argv[0],std::stoi(argv[3]));

    //odd lab 6

    obj->add_lab_student(argv[1],argv[2],argv[3],std::stoi(argv[0]));
    return 0;
}

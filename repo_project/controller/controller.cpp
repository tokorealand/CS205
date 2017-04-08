#include "controller.h"



Controller::Controller(DBTool *tool):DBTable(tool)
{
    this->class_tool = tool;
}


Controller::~Controller()
{
    for(Class* it : classes)
    {
        delete it;
    }
    for(Section* it : sections)
    {
        delete it;
    }
    for(Student* it : students)
    {
        delete it;
    }
    for(Lab* it : labs)
    {
        delete it;
    }
}

void Controller::add_class(std::string classID, int number_of_sections)
{
    Class *cla = new Class(classID,number_of_sections,class_tool,table_class);
    classes.push_back(cla);

}

void Controller::add_section(std::string sectionID, string classID)
{
    Section *sec = new Section(sectionID, classID,class_tool,table_section);
    sections.push_back(sec);
}

void Controller::add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname)
{
    Student *stu = new Student(studentID,sectionID, firstname, lastname, class_tool,table_student);
    students.push_back(stu);
}

void Controller::add_lab(std::string labID, string studentID, string labName, string labNumber, DBTool *tool, string table)
{

}

//Used to retriveve all players in database
bool Controller::select_all_classes() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_sections  = "SELECT * FROM ";
    sql_select_all_sections += table_class;
    sql_select_all_sections += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_classes.c_str(),
                           cb_select_all_sections,
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
bool Controller::drop_class_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_class="DROP TABLE ";
    sql_drop_class += table_class;
    sql_drop_class += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_class.c_str(),
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
int cb_select_all_classes(void  *data,
                          int    argc,
                          char **argv,
                          char **azColName)
{



    std::cerr << "cb_select_all_sections being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Controller *obj = (Controller *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? std::string(argv[i]) : "NULL")
                      << std::endl;



    }

    obj->add_class(argv[0],std::stoi(argv[1]));
    //old from lab 6

    return 0;
}


//Used to retriveve all sections in database
bool Controller::select_all_sections() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_sections  = "SELECT * FROM ";
    sql_select_all_sections += table_section;
    sql_select_all_sections += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_sections.c_str(),
                           cb_select_all_sections,
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
bool Controller::drop_section_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_section="DROP TABLE ";
    sql_drop_section += table_section;
    sql_drop_section += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_section.c_str(),
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
int cb_select_all_sections(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName)
{



    std::cerr << "cb_select_all_sections being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Controller *obj = (Controller *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? std::string(argv[i]) : "NULL")
                      << std::endl;



    }

    obj->add_section(argv[0],argv[1]);
    //old from lab 6

    return 0;
}


//Used to retriveve all students in database
bool Controller::select_all_students() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_students  = "SELECT * FROM ";
    sql_select_all_students += table_student;
    sql_select_all_students += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_students.c_str(),
                           cb_select_all_students,
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
bool Controller::drop_student_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_student="DROP TABLE ";
    sql_drop_student += table_student;
    sql_drop_student += ";";


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

//Call back for select_all_pgh
int cb_select_all_students(void  *data,
                           int    argc,
                           char **argv,
                           char **azColName)
{



    std::cerr << "cb_select_all_sections being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Controller *obj = (Controller *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? std::string(argv[i]) : "NULL")
                      << std::endl;



    }

    obj->add_student(argv[0],argv[1],argv[2],argv[3]);
    //old from lab 6

    return 0;
}


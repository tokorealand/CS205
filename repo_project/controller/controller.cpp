#include "controller.h"



Controller::Controller(DBTool *tool):DBTable(tool)
{
    this->class_tool = tool;
    total_recall();
}


Controller::~Controller()
{
    total_drop();
    for(Year* it : years)
    {
        delete it;
    }
    for(Semester* it : semesters)
    {
        delete it;
    }
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
    for(Component* it : components)
    {
        delete it;
    }
    for(Comment* it : comments)
    {
        delete it;
    }

}

std::string Controller::student_list()
{
    std::string list = "";
    for(Student* it: students)
    {
        list+=it->get_first_name();

    }
    return list;
}

void Controller::total_recall()
{
    select_all_years();
    select_all_semesters();
    select_all_classes();
    select_all_sections();
    select_all_students();
    select_all_labs();
    select_all_components();

}

void Controller::total_drop()
{
    drop_comments_table();
    drop_component_table();
    drop_lab_table();
    drop_student_table();
    drop_section_table();
    drop_class_table();
    drop_semester_table();
    drop_year_table();
}


Year* Controller::get_year(std::string id)
{
    for(Year* it: years)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

Semester* Controller::get_semester(std::string id)
{
    for(Semester* it: semesters)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}


Class* Controller::get_class(std::string id)
{
    for(Class* it: classes)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

Section* Controller::get_section(std::string id)
{
    for(Section* it: sections)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

Student* Controller::get_student(std::string id)
{
    for(Student* it: students)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

Lab* Controller::get_lab(std::string id)
{
    for(Lab* it: labs)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

Component* Controller::get_component(std::string id)
{
    for(Component* it: components)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

Comment* Controller::get_comment(std::string id)
{
    for(Comment* it: comments)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

bool Controller::item_exist(std::string id, std::string type)
{
    if(type == "year")
    {
        for(Year* it : years)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

    if(type == "semester")
    {
        for(Semester* it : semesters)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

    if(type == "class")
    {
        for(Class* it : classes)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

    if(type == "section")
    {
        for(Section* it : sections)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }
    if(type == "student")
    {
        for(Student* it : students)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }
    if(type == "lab")
    {
        for(Lab* it : labs)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

    if(type == "component")
    {
        for(Component* it : components)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }

    if(type == "comment")
    {
        for(Comment* it : comments)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

std::vector<Year*> Controller:: get_years()
{
    return years;
}

std::vector<Semester*> Controller:: get_semesters()
{
    return semesters;
}

std::vector<Class*> Controller:: get_classes()
{
    return classes;
}



void Controller::add_year(std::string yearID)
{
    if(item_exist(yearID,"year"))
    {
        return;
    }

    Year *yea = new Year(yearID,class_tool,table_year);
    years.push_back(yea);
}

void Controller::add_semester(std::string semesterID, std::string yearID)
{
    if(item_exist(semesterID,"semester"))
    {
        return;
    }

    Semester *sem = new Semester(semesterID, yearID,class_tool,table_semester);
    semesters.push_back(sem);
    get_year(yearID)->add_semester(sem);
}



void Controller::add_class(std::string classID,std::string semesterID)
{
    if(item_exist(classID,"class"))
    {
        return;
    }
    Class *cla = new Class(classID,semesterID,class_tool,table_class);
    classes.push_back(cla);
    get_semester(semesterID)->add_class(cla);


}

void Controller::add_section(std::string sectionID, string classID)
{
    if(item_exist(sectionID,"section"))
    {
        return;
    }

    Section *sec = new Section(sectionID, classID,class_tool,table_section);
    sections.push_back(sec);
    get_class(classID)->add_section(sec);

}

void Controller::add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname)
{
    if(item_exist(studentID,"student"))
    {
        return;
    }
    Student *stu = new Student(studentID,sectionID, firstname, lastname, class_tool,table_student);
    students.push_back(stu);
    get_section(sectionID)->add_student(stu);
}

void Controller::add_lab(std::string labID, string studentID, string labName, string labNumber)
{
    if(item_exist(labID,"lab"))
    {
        return;
    }
    Lab *la = new Lab(labID, studentID, labName, labNumber, class_tool,table_lab);
    labs.push_back(la);
    get_student(studentID)->add_lab(la);
}

void Controller::add_component(std::string componentID, string labID, string text)
{
    if(item_exist(componentID,"component"))
    {
        return;
    }
    Component *com = new Component(componentID, labID, text, class_tool,table_component);
    components.push_back(com);
    get_lab(labID)->add_component(com);



}

void Controller::add_comment(std::string commentID, std::string labID, std::string linenumber, std::string commentphrase, std::string rubricsection, std::string highlight, std::string points)
{
    if(item_exist(commentID,"comment"))
    {
        return;
    }
    Comment *com = new Comment(commentID, labID, linenumber,commentphrase,rubricsection, highlight,points, class_tool,table_comment);
    comments.push_back(com);
    get_lab(labID)->add_comment(com);
}



//Used to retriveve all players in database
bool Controller::select_all_years() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_year  = "SELECT * FROM ";
    sql_select_all_year+= table_year;
    sql_select_all_year += ";";


    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_year.c_str(),
                           cb_select_all_years,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

                std::cerr << table_name
                          << " template ::"
                          << std::endl
                          << "SQL error: "
                          << zErrMsg;

                sqlite3_free(zErrMsg);
    }

    return retCode;
}


// Removes the db table from the database.
bool Controller::drop_year_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_year="DROP TABLE ";
    sql_drop_year += table_year;
    sql_drop_year += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_year.c_str(),
                           cb_drop,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if( retCode != SQLITE_OK ){

        std::cerr << sql_drop
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }


    return retCode;
}

//Call back for select_all_pgh
int cb_select_all_years(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName)
{



    std::cerr << "cb_select_all_years being called\n";

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

    obj->add_year(argv[0]);


    return 0;
}


////////////////////////////
//Used to retriveve all players in database
bool Controller::select_all_semesters() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_semester  = "SELECT * FROM ";
    sql_select_all_semester+= table_semester;
    sql_select_all_semester += ";";


    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_semester.c_str(),
                           cb_select_all_semesters,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

                std::cerr << table_name
                          << " template ::"
                          << std::endl
                          << "SQL error: "
                          << zErrMsg;

                sqlite3_free(zErrMsg);
    }

    return retCode;
}


// Removes the db table from the database.
bool Controller::drop_semester_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_semester="DROP TABLE ";
    sql_drop_semester += table_semester;
    sql_drop_semester += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_semester.c_str(),
                           cb_drop,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if( retCode != SQLITE_OK ){

        std::cerr << sql_drop
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }


    return retCode;
}

//Call back for select_all_pgh
int cb_select_all_semesters(void  *data,
                            int    argc,
                            char **argv,
                            char **azColName)
{



    std::cerr << "cb_select_all_semesters being called\n";

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

    obj->add_semester(argv[0],argv[1]);


    return 0;
}



//////////////////////////////////////
//Used to retriveve all players in database
bool Controller::select_all_classes() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_classes  = "SELECT * FROM ";
    sql_select_all_classes+= table_class;
    sql_select_all_classes += ";";


    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_classes.c_str(),
                           cb_select_all_classes,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

                std::cerr << table_name
                          << " template ::"
                          << std::endl
                          << "SQL error: "
                          << zErrMsg;

                sqlite3_free(zErrMsg);
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

        std::cerr << sql_drop
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }


    return retCode;
}

//Call back for select_all_pgh
int cb_select_all_classes(void  *data,
                          int    argc,
                          char **argv,
                          char **azColName)
{



    std::cerr << "cb_select_all_classes being called\n";

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

    obj->add_class(argv[0],argv[1]);


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

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
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



    std::cerr << "cb_select_all_students being called\n";

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

////////

//Used to retriveve all labs in database
bool Controller::select_all_labs() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_labs = "SELECT * FROM ";
    sql_select_all_labs += table_lab;
    sql_select_all_labs += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_labs.c_str(),
                           cb_select_all_labs,
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
bool Controller::drop_lab_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_lab="DROP TABLE ";
    sql_drop_lab += table_lab;
    sql_drop_lab += ";";


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
int cb_select_all_labs(void  *data,
                       int    argc,
                       char **argv,
                       char **azColName)
{



    std::cerr << "cb_select_all_labs being called\n";

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

    obj->add_lab(argv[0],argv[1],argv[2],argv[3]);

    return 0;
}

//Used to retriveve all labs in database
bool Controller::select_all_components() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_components = "SELECT * FROM ";
    sql_select_all_components += table_component;
    sql_select_all_components += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_components.c_str(),
                           cb_select_all_components,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

//Call back for select_all_pgh
int cb_select_all_components(void  *data,
                             int    argc,
                             char **argv,
                             char **azColName)
{



    std::cerr << "cb_select_all_components being called\n";

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

    obj->add_component(argv[0],argv[1],argv[2]);
    //old from lab 6

    return 0;
}

// Removes the db table from the database.
bool Controller::drop_component_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_component="DROP TABLE ";
    sql_drop_component += table_component;
    sql_drop_component += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_component.c_str(),
                           cb_drop,
                           this,
                           &zErrMsg          );

    // Process a failed call.
    if( retCode != SQLITE_OK ){

        std::cerr << sql_drop
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }


    return retCode;
}

//Call back for select_all_pgh
int cb_select_all_commentss(void  *data,
                            int    argc,
                            char **argv,
                            char **azColName)
{



    std::cerr << "cb_select_all_commentss being called\n";

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

    //obj->add_lab(argv[0],argv[1],argv[2],argv[3]);
    //old from lab 6

    return 0;
}

// Removes the db table from the database.
bool Controller::drop_comments_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_comment="DROP TABLE ";
    sql_drop_comment += table_comment;
    sql_drop_comment += ";";


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

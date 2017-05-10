#include "controller.h"



Controller::Controller(DBTool *tool):DBTable(tool)
{
    this->class_tool = tool;
    total_recall();
}




/**
Destructor for controller that drops the tables in the database while calling the
destructors in the contained objects.
*/
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
    for(RubricObject* it : rubrics)
    {
        delete it;
    }
    for(RubricSection* it : rubricsections)
    {
        delete it;
    }


}

/**
Returns names of all contained students.
*/
std::string Controller::student_list()
{
    std::string list = "";
    for(Student* it: students)
    {
        list+=it->get_first_name();

    }
    return list;
}

/**
Repopulates the engine from the database.
*/
void Controller::total_recall()
{
    select_all_years();
    select_all_semesters();
    select_all_classes();
    select_all_sections();
    select_all_students();
    select_all_labs();
    select_all_components();
    select_all_rubrics();
    select_all_rubricsections();
    select_all_commentss();

}

/**
Drops all the tables in the database.
*/
void Controller::total_drop()
{
    drop_rubricsections_table();
    drop_rubrics_table();
    drop_comments_table();
    drop_component_table();
    drop_lab_table();
    drop_student_table();
    drop_section_table();
    drop_class_table();
    drop_semester_table();
    drop_year_table();
}

/**
Used for testing the total_drop method.
*/
void Controller::test_drop()
{
    drop_rubricsections_table();
    drop_rubrics_table();
    drop_comments_table();
    drop_component_table();
    drop_lab_table();
    drop_student_table();
    drop_section_table();
    drop_class_table();
    drop_semester_table();
    drop_year_table();
}


/**
 *
 * GET METHODS
 *
 */

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

RubricObject* Controller::get_rubric(std::string id)
{
    for(RubricObject* it: rubrics)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
}

RubricSection* Controller::get_rubricsection(std::string id)
{
    for(RubricSection* it: rubricsections)
    {
        if(it->get_id() == id)
        {
            return it;
        }

    }
    return NULL;
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

std::vector<Comment*> Controller::get_comments()
{
    return comments;
}


/**
Runs the given ID through the vector of the specified type to check for a match.
If a match is found then true is returned, otherwise returns false.
*/
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

    if(type == "rubric")
    {
        for(RubricObject* it : rubrics)
        {
            if(it->get_id() == id)
            {
                return true;
            }
        }
        return false;
    }
    if(type == "rubricsection")
    {
        for(RubricSection* it : rubricsections)
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



/**
 *
 * ADD METHODS
 *
 */



/**
 *Adds a year using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - yearID
 *@returns bool - adding operation outcome
 */
bool Controller::add_year(std::string yearID)
{
    if(item_exist(yearID,"year"))
    {
        return false;
    }

    Year *yea = new Year(yearID,class_tool,table_year);
    years.push_back(yea);
    return true;
}



/**
 *Adds a semester using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - semesterID
 *@param string - yearID
 *@returns bool - adding operation outcome
 */
bool Controller::add_semester(std::string semesterID, std::string yearID)
{
    if(item_exist(semesterID,"semester"))
    {
        return false;
    }

    Semester *sem = new Semester(semesterID, yearID,class_tool,table_semester);
    semesters.push_back(sem);
    //adds the semester object to the appropiate year container
    get_year(yearID)->add_semester(sem);
    return true;
}


/**
 *Adds a class using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - classID
 *@param string - semesterID
 *@returns bool - adding operation outcome
 */
bool Controller::add_class(std::string classID,std::string semesterID)
{
    if(item_exist(classID,"class"))
    {
        return false;
    }
    Class *cla = new Class(classID,semesterID,class_tool,table_class);
    classes.push_back(cla);
    //adds the class object to the appropiate semester container
    get_semester(semesterID)->add_class(cla);
    return true;

}


/**
 *Adds a section using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - sectionID
 *@param string - classID
 *@returns bool - adding operation outcome
 */
bool Controller::add_section(std::string sectionID, string classID)
{
    if(item_exist(sectionID,"section"))
    {
        return false;
    }

    Section *sec = new Section(sectionID, classID,class_tool,table_section);
    sections.push_back(sec);
    //adds the section object to the appropiate class container
    get_class(classID)->add_section(sec);
    return true;

}


/**
 *Adds a student using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - studentID
 *@param string - sectionID
 *@param string - firstname
 *@param string - lastname
 *@returns bool - adding operation outcome
 */
bool Controller::add_student(std::string studentID, std::string sectionID, std::string firstname, std::string lastname)
{
    if(item_exist(studentID,"student"))
    {
        return false;
    }
    Student *stu = new Student(studentID,sectionID, firstname, lastname, class_tool,table_student);
    students.push_back(stu);
    //adds the student object to the appropiate section container
    get_section(sectionID)->add_student(stu);
    return true;
}

/**
 *Adds a lab using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - labID
 *@param string - studentID
 *@param string - labName
 *@param string - labNumber
 *@param string - graded
 *@returns bool - adding operation outcome
 */
bool Controller::add_lab(std::string labID, string studentID, string labName, string labNumber, std::string graded)
{
    if(item_exist(labID,"lab"))
    {
        return false;
    }
    Lab *la = new Lab(labID, studentID, labName, labNumber,graded, class_tool,table_lab);
    labs.push_back(la);
    //adds the lab object to the appropiate student container
    get_student(studentID)->add_lab(la);
    //adds the lab object to the appropiate class container for stat calculations
    get_class( get_section( get_student(studentID)->get_section_id())->get_class_id())->add_lab(la);
    return true;
}

/**
 *Adds a component using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - componentID
 *@param string - labID
 *@param string - text
 *@returns bool - adding operation outcome
 */
bool Controller::add_component(std::string componentID, string labID, string text)
{
    if(item_exist(componentID,"component"))
    {
        return false;
    }
    Component *com = new Component(componentID, labID, text, class_tool,table_component);
    components.push_back(com);
    //adds the component object to the appropiate lab container
    get_lab(labID)->add_component(com);
    return true;



}


/**
 *Adds a comment using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - commentID
 *@param string - componentID
 *@param string - linenumber
 *@param string - commentphrase
 *@param string - rubricsection
 *@param string - highlight
 *@param string - points
 *@returns bool - adding operation outcome
 */
bool Controller::add_comment(std::string commentID, std::string componentID, std::string linenumber, std::string commentphrase, std::string rubricsection, std::string highlight, std::string points)
{
    if(item_exist(commentID,"comment"))
    {
        return false;
    }
    Comment *com = new Comment(commentID, componentID, linenumber,commentphrase,rubricsection, highlight,points, class_tool,table_comment);
    comments.push_back(com);
    //adds the comment object to the appropiate component container
    get_component(componentID)->add_comment(com);
    return true;
}

/**
 *Adds a rubric using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - rubricID
 *@param string - classID
 *@returns bool - adding operation outcome
 */
bool Controller::add_rubric(std::string rubricID, std::string classID)
{
    if(item_exist(rubricID,"rubric"))
    {
        return false;
    }
    RubricObject *rub = new RubricObject(rubricID,classID,class_tool,table_rubric);
    rubrics.push_back(rub);
    //adds the rubric object to the appropiate class container
    get_class(classID)->add_rubric(rub);
    return true;
}

/**
 *Adds a rubricsection using the given ID. Checks whether item already exist before
 * adding. If the item does not already exist then it is added. Returns true if
 * added otherwise returns false.
 *@param string - rubricsectionID
 *@param string - rubricID
 *@param string - description
 *@param string - points
 *@param string - color
 *@returns bool - adding operation outcome
 */
bool Controller::add_rubricsection(std::string rubricsectionID, std::string rubricID,std::string description, std::string points, std::string color)
{
    if(item_exist(rubricsectionID,"rubricsection"))
    {
        return false;
    }
    RubricSection *rubs = new RubricSection(rubricsectionID,rubricID,description,points,color,class_tool,table_rubricsection);
    rubricsections.push_back(rubs);
    //adds the rubricsection object to the appropiate rubric container
    get_rubric(rubricID)->add_rubric_section(rubs);
    return true;
}



//Used to retriveve all years in database
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


// Removes the year table from the database.
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

//Call back for select_all_years
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


//Used to retriveve all semesters in database
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


// Removes the semester table from the database.
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

//Call back for select_all_semesters
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



//Used to retriveve all classes in database
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


// Removes the class table from the database.
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

//Call back for select_all_classes
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


// Removes the section table from the database.
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

//Call back for select_all_section
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


// Removes the student table from the database.
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

//Call back for select_all_students
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

    return 0;
}



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


// Removes the lab table from the database.
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

//Call back for select_all_labs
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

    obj->add_lab(argv[0],argv[1],argv[2],argv[3],argv[4]);

    return 0;
}

//Used to retriveve all components in database
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

//Call back for select_all_components
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

    return 0;
}

// Removes the component table from the database.
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


//Used to retriveve all comments in database
bool Controller::select_all_commentss() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_comments = "SELECT * FROM ";
    sql_select_all_comments += table_comment;
    sql_select_all_comments += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_comments.c_str(),
                           cb_select_all_commentss,
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


//Call back for select_all_comments
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

    obj->add_comment(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]);

    return 0;
}

// Removes the comments table from the database.
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

//Used to retriveve all rubrics in database
bool Controller::select_all_rubrics() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_rubrics = "SELECT * FROM ";
    sql_select_all_rubrics += table_rubric;
    sql_select_all_rubrics += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_rubrics.c_str(),
                           cb_select_all_rubrics,
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


//Call back for select_all_rubrics
int cb_select_all_rubrics(void  *data,
                          int    argc,
                          char **argv,
                          char **azColName)
{



    std::cerr << "cb_select_all_rubrics being called\n";

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

    obj->add_rubric(argv[0],argv[1]);

    return 0;
}

// Removes the rubrics table from the database.
bool Controller::drop_rubrics_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_rubric="DROP TABLE ";
    sql_drop_rubric += table_rubric;
    sql_drop_rubric += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_rubric.c_str(),
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

//Used to retriveve all rubricsections in database
bool Controller::select_all_rubricsections() {
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all_rubricsections = "SELECT * FROM ";
    sql_select_all_rubricsections += table_rubricsection;
    sql_select_all_rubricsections += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all_rubricsections.c_str(),
                           cb_select_all_rubricsections,
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


//Call back for select_all_rubricsections
int cb_select_all_rubricsections(void  *data,
                                 int    argc,
                                 char **argv,
                                 char **azColName)
{



    std::cerr << "cb_select_all_rubricsections being called\n";

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

    obj->add_rubricsection(argv[0],argv[1],argv[2],argv[3],argv[4]);

    return 0;
}

// Removes the rubricsections table from the database.
bool Controller::drop_rubricsections_table() {

    // Initialize local variables.
    int   retCode = 0;
    char *zErrMsg = 0;
    std::string sql_drop_rubricsections="DROP TABLE ";
    sql_drop_rubricsections += table_rubricsection;
    sql_drop_rubricsections += ";";


    // Call sqlite to run the SQL call using the
    // callback to store any results.
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop_rubricsections.c_str(),
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

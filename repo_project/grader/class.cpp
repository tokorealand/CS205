#include "class.h"

Class::Class(std::string classID, int number_of_sections, DBTool *tool, std::string table):DBTable(tool,table)
{
    this->number_of_sections = number_of_sections;
    this->id = classID;
    this->tool = tool;

    store_add_row_sql();

    store_create_sql();
}


Class::~Class()
{
    //    for(std::vector<Section*>::iterator it = sections.begin();
    //        it != sections.end(); ++it)
    //    {
    //        delete *it;
    //    }

    build_table();
    add_row(id,number_of_sections);
}

std::string Class:: get_id()
{
    return id;
}


///*
// *Creates objects from the database
//**/
//void Class::repopulate()
//{

//    select_all_sections_in_class();
//    drop_section_table();

//}

//void Class::increment_section()
//{
//    sectioncounter++;
//}

/*
 *Creates students and adds them
**/
void Class::add_section()
{
    //    sectioncounter++;
    //    std::cout<<sectioncounter;

    //    Section *sectoadd = new Section(sectioncounter, studentcounter,labcounter,tool,table_section);
    //    sections.push_back(sectoadd);

}



Section* Class::get_section(int sectionid)
{/*
    Section *s;
    for(std::vector<Section*>::iterator it = sections.begin();
        it != sections.end(); ++it)
    {
        s = (*it);
        if(s->get_id() == sectionid)
        {
            return s;
        }*/
    //  }
    return NULL;
}

////Used to retriveve all players in database
//bool Class::select_all_sections_in_class() {
//    int   retCode = 0;
//    char *zErrMsg = 0;

//    sql_select_all_sections_in_class  = "SELECT * FROM ";
//    sql_select_all_sections_in_class += table_section;
//    sql_select_all_sections_in_class += ";";

//    retCode = sqlite3_exec(curr_db->db_ref(),
//                           sql_select_all_sections_in_class.c_str(),
//                           cb_select_all_sections_in_class,
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
//bool Class::drop_section_table() {

//    // Initialize local variables.
//    int   retCode = 0;
//    char *zErrMsg = 0;
//    std::string sql_drop_section="DROP TABLE ";
//    sql_drop_section += table_section;
//    sql_drop_section += ";";


//    // Call sqlite to run the SQL call using the
//    // callback to store any results.
//    retCode = sqlite3_exec(curr_db->db_ref(),
//                           sql_drop_section.c_str(),
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
//int cb_select_all_sections_in_class(void  *data,
//                                    int    argc,
//                                    char **argv,
//                                    char **azColName)
//{



//    std::cerr << "cb_select_all_sections being called\n";

//    if(argc < 1) {
//        std::cerr << "No data presented to callback "
//                  << "argc = " << argc
//                  << std::endl;
//    }

//    int i;

//    Class *obj = (Class *) data;

//    std::cout << "------------------------------\n";
//    std::cout << obj->get_name()
//              << std::endl;

//    for(i = 0; i < argc; i++){
//        std::cout << azColName[i]
//                     << " = "
//                     <<  (argv[i] ? std::string(argv[i]) : "NULL")
//                      << std::endl;



//    }
//    // obj->increment_section();
//    std::cout<<obj->sectioncounter<<"SSSSS";
//    obj->add_section();
//    //old from lab 6

//    return 0;
//}


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


    std::cerr << "calling store_create_sql from Section\n";
    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id TEXT PRIMARY KEY NOT NULL, ";
    sql_create += "  number_of_sections INT NOT NULL";

    sql_create += " );";

}


bool Class::add_row(std::string id, int number_of_sections) {
    int   retCode = 0;
    char *zErrMsg = 0;
    char  tempval[128];



    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, number_of_sections )";
    sql_add_row += "VALUES (";


    sql_add_row += "\"";
    sql_add_row += std::string(id);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", number_of_sections);
    sql_add_row += tempval;
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

/** Call back for adding to student table
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

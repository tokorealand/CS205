#include "gtest/gtest.h"
#include "../grader/section.h"
#include "../grader/student.h"
#include "../grader/dbtable.h"
#include "../grader/dbtool.h"
#include "../grader/lab.h"
#include "../grader/class.h"
#include "../grader/semester.h"
#include "../grader/year.h"
#include "../grader/component.h"
#include "../grader/commentengine.h"
#include "../grader/comment.h"
#include "../grader/rubricobject.h"
#include "../grader/rubricsection.h"
#include"../controller/controller.h"
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <string>

//TEST(PlayerGameHistory, findemptyplayer)
//{
//    DBTool *tool = new DBTool();
//    PlayerGameHistory pgh(tool);
//    int check;
//    check=pgh.find_player_avg("luis","lopez");
//    ASSERT_EQ(check,-1);
//}

/**
 * @brief TEST for adding a year
 */
TEST(Controller,Addyear)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
   Year* yr= con.get_year("1");

   ASSERT_EQ(yr,con.get_year("1"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding a year and checking with a different item_exist method
 */
TEST(Controller,Addyear2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");


   ASSERT_EQ(true,con.item_exist("1","year"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding two years
 */
TEST(Controller,Addtwoyears)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_year("2");


   ASSERT_NE(con.get_year("1"),con.get_year("2"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding two years with different order
 */
TEST(Controller,Addtwoyears2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("2");
    con.add_year("1");


   ASSERT_NE(con.get_year("1"),con.get_year("2"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST to make sure you can not add a year twice
 */
TEST(Controller,Addyeartwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("2");
 ASSERT_EQ(false,con.add_year("2"));


   con.test_drop();
   delete tool;
}

/**
 * @brief TEST showing accuracy of returned vector
 */
TEST(Controller,Yearvector)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("2");
    con.add_year("3");
    con.add_year("4");
    con.add_year("5");

    std::vector<Year*> holder;

    holder=con.get_years();
    std::string check="";
    for(Year* y : holder )
    {
       check+=y->get_id();
    }

    ASSERT_EQ("2345",check);
   con.test_drop();
   delete tool;
}


/**
 * @brief TEST for adding a semester
 */
TEST(Controller,Addsemester)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
   Semester* sm= con.get_semester("spring1");

   ASSERT_EQ(sm,con.get_semester("spring1"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding a semester and checking with a different item_exist method
 */
TEST(Controller,Addsemester2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");


   ASSERT_EQ(true,con.item_exist("spring1","semester"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding two semesters
 */
TEST(Controller,Addtwosemesters)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_semester("fall1","1");



   ASSERT_NE(con.get_semester("spring1"),con.get_semester("fall1"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding two semester with different order
 */
TEST(Controller,Addtwosemesters2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("fall1","1");
    con.add_semester("spring1","1");


   ASSERT_NE(con.get_semester("fall1"),con.get_semester(
                 "spring1"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST to make sure you can not add a semester twice
 */
TEST(Controller,Addsemestertwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("fall1","1");
 ASSERT_EQ(false,con.add_semester("fall1","1"));


   con.test_drop();
   delete tool;
}

/**
 * @brief TEST showing accuracy of returned vector
 */
TEST(Controller,Semestervector)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("fall1","1");

    con.add_semester("spring1","1");



    std::vector<Semester*> holder;

    holder=con.get_semesters();
    std::string check="";
    for(Semester* y : holder )
    {
       check+=y->get_id();
    }

    ASSERT_EQ("fall1spring1",check);
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding a class
 */
TEST(Controller,Addclass)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
   Class* sm= con.get_class("class1");

   ASSERT_EQ(sm,con.get_class("class1"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding a class and checking with a different item_exist method
 */
TEST(Controller,Addclass2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");



   ASSERT_EQ(true,con.item_exist("class1","class"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding two classes
 */
TEST(Controller,Addtwoclasses)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_class("class2","spring1");




   ASSERT_NE(con.get_class("class1"),con.get_class("class2"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST for adding two classes with different order
 */
TEST(Controller,Addtwoclasses2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");
    con.add_class("class1","spring1");


   ASSERT_NE(con.get_class("class1"),con.get_class(
                 "class2"));
   con.test_drop();
   delete tool;
}

/**
 * @brief TEST to make sure you can not add a class twice
 */
TEST(Controller,Addclasstwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring","1");
    con.add_class("class2","spring1");

 ASSERT_EQ(false,con.add_class("class2","spring1"));


   con.test_drop();
   delete tool;
}

/**
 * @brief TEST showing accuracy of returned vector
 */
TEST(Controller,Classvector)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");
    con.add_class("class1","spring1");


    std::vector<Class*> holder;

    holder=con.get_classes();
    std::string check="";
    for(Class* y : holder )
    {
       check+=y->get_id();
    }

    ASSERT_EQ("class2class1",check);
   con.test_drop();
   delete tool;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

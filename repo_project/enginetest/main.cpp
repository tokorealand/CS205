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
   //delete tool;
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
  // delete tool;
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
   //delete tool;
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
   //delete tool;
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
  // delete tool;
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
    con.add_year("7");

    std::vector<Year*> holder;

    holder=con.get_years();
    std::string check="";
    for(Year* y : holder )
    {
       check+=y->get_id();
    }

    ASSERT_EQ("123457",check);
   con.test_drop();
  // delete tool;
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
   //delete tool;
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
   //delete tool;
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
   //delete tool;
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
   //delete tool;
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
   //delete tool;
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
     con.add_semester("spring2","1");





    std::vector<Semester*> holder;

    holder=con.get_semesters();
    std::string check="";
    for(Semester* y : holder )
    {
       check+=y->get_id();
    }

    ASSERT_EQ("spring1fall1spring2",check);
   con.test_drop();
   //delete tool;
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
  // delete tool;
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
   //delete tool;
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
   //delete tool;
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
  // delete tool;
}

/**
 * @brief TEST to make sure you can not add a class twice
 */
TEST(Controller,Addclasstwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");

 ASSERT_EQ(false,con.add_class("class2","spring1"));


   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding a rubric
 */
TEST(Controller,Addrubric)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_rubric("r1","class1");
   RubricObject* sm= con.get_rubric("r1");

   ASSERT_EQ(sm,con.get_rubric("r1"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding a rubric and checking with a different item_exist method
 */
TEST(Controller,Addrubric2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_rubric("r1","class1");




   ASSERT_EQ(true,con.item_exist("r1","rubric"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding two rubrics
 */
TEST(Controller,Addtworubrics)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_rubric("r1","class1");
    con.add_rubric("r2","class1");





   ASSERT_NE(con.get_rubric("r1"),con.get_rubric("r2"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding two rubrics with different order
 */
TEST(Controller,Addtworubrics2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_rubric("r2","class1");
    con.add_rubric("r1","class1");



   ASSERT_NE(con.get_rubric("r2"),con.get_rubric(
                 "r1"));
   con.test_drop();
 //  delete tool;
}

/**
 * @brief TEST to make sure you can not add a rubric twice
 */
TEST(Controller,Addrubrictwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_rubric("r1","class1");


 ASSERT_EQ(false,con.add_rubric("r1","class1"));



   con.test_drop();
  // delete tool;
}


/**
 * @brief TEST for adding a section
 */
TEST(Controller,Addsection)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
   Section* sm= con.get_section("s1");

   ASSERT_EQ(sm,con.get_section("s1"));
   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding a section and checking with a different item_exist method
 */
TEST(Controller,Addsection2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");



   ASSERT_EQ(true,con.item_exist("s1","section"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding two sections
 */
TEST(Controller,Addtwosections)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_section("s2","class1");





   ASSERT_NE(con.get_section("s1"),con.get_section("s2"));
   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding two sections with different order
 */
TEST(Controller,Addtwosections2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_section("s2","class1");



   ASSERT_NE(con.get_section("s1"),con.get_section(
                 "s2"));
   con.test_drop();
 //  delete tool;
}

/**
 * @brief TEST to make sure you can not add a section twice
 */
TEST(Controller,Addsectiontwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");
    con.add_section("s1","class2");
    con.add_section("s2","class2");



 ASSERT_EQ(false,con.add_section("s2","class2"));


   con.test_drop();
   //delete tool;
}


/**
 * @brief TEST for adding a student
 */
TEST(Controller,Addstudent)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
   Student* sm= con.get_student("luis");

   ASSERT_EQ(sm,con.get_student("luis"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding a student and checking with a different item_exist method
 */
TEST(Controller,Addstudent2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");




   ASSERT_EQ(true,con.item_exist("luis","student"));
   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding two students
 */
TEST(Controller,Addtwostudents)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_student("luis2","s1","luis","lopez");






   ASSERT_NE(con.get_student("luis"),con.get_student("luis2"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding two students with different order
 */
TEST(Controller,Addtwostudents2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis2","s1","luis","lopez");
    con.add_student("luis","s1","luis","lopez");



   ASSERT_NE(con.get_student("luis"),con.get_student(
                 "luis2"));
   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST to make sure you can not add a student twice
 */
TEST(Controller,Addstudenttwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");
    con.add_section("s1","class2");
    con.add_student("luis","s1","luis","lopez");



 ASSERT_EQ(false,con.add_student("luis","s1","luis","lopez"));



   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding a lab
 */
TEST(Controller,Addlab)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1","0");
   Lab* sm= con.get_lab("l1");

   ASSERT_EQ(sm,con.get_lab("l1"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding a lab and checking with a different item_exist method
 */
TEST(Controller,Addlab2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1","0");





   ASSERT_EQ(true,con.item_exist("l1","lab"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST for adding two labs
 */
TEST(Controller,Addtwolabs)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1","0");
    con.add_lab("l2","luis","recursion","2","0");







   ASSERT_NE(con.get_lab("l2"),con.get_lab("l1"));
   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding two labs with different order
 */
TEST(Controller,Addtwolabs2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l2","luis","recursion","2","0");
    con.add_lab("l1","luis","recursion","1","0");




   ASSERT_NE(con.get_lab("l1"),con.get_lab(
                 "l2"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST to make sure you can not add a lab twice
 */
TEST(Controller,Addlabtwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");
    con.add_section("s1","class2");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1","0");





 ASSERT_EQ(false,con.add_lab("l1","luis","recursion","1","0"));



   con.test_drop();
  // delete tool;
}

/**
 * @brief TEST for adding a component
 */
TEST(Controller,Addcomponent)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1","0");
    con.add_component("c1","l1","./afd.txt");
   Component* sm= con.get_component("c1");

   ASSERT_EQ(sm,con.get_component("c1"));
   con.test_drop();
//   delete tool;
}

/**
 * @brief TEST for adding a component and checking with a different item_exist method
 */
TEST(Controller,Addcomponent2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1","0");
    con.add_component("c1","l1","/afd.txt");

   ASSERT_EQ(true,con.item_exist("c1","component"));
   con.test_drop();
//   delete tool;
}

/**
 * @brief TEST for adding two labs
 */
TEST(Controller,Addtwocomponents)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1", "0");
    con.add_component("c1","l1","addadsa");
    con.add_component("c2","l1","addadsa");



   ASSERT_NE(con.get_component("c2"),con.get_component("c1"));
   con.test_drop();
//   delete tool;
}

/**
 * @brief TEST for adding two components with different order
 */
TEST(Controller,Addtwocomponents2)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class1","spring1");
    con.add_section("s1","class1");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1", "0");
    con.add_component("c2","l1","addadsa");
    con.add_component("c1","l1","addadsa");






   ASSERT_NE(con.get_component("c1"),con.get_component(
                 "c2"));
   con.test_drop();
   //delete tool;
}

/**
 * @brief TEST to make sure you can not add a component twice
 */
TEST(Controller,Addcomponenttwice)
{
    DBTool *tool = new DBTool("777");
    Controller con(tool);
    con.add_year("1");
    con.add_semester("spring1","1");
    con.add_class("class2","spring1");
    con.add_section("s1","class2");
    con.add_student("luis","s1","luis","lopez");
    con.add_lab("l1","luis","recursion","1", "0");
    con.add_component("c1","l1","addadsa");

 ASSERT_EQ(false,    con.add_component("c1","l1","addadsa"));

   con.test_drop();
 //  delete tool;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


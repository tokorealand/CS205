#include <iostream>
#include "section.h"
#include "lab.h"
#include "student.h"
#include "dbtool.h"
#include "commentengine.h"
#include "class.h"
#include <string>
#include "grader.h"
using namespace std;

int main(int argc, char *argv[])
{

   Grader g;
   g.add_class("Class1",2);
   g.add_section("C1S1","Class1");
   g.add_student("s1","C1S1","lu","lo");

}

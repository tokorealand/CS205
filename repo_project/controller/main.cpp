#include <iostream>
#include "controller.h"
#include "../grader/dbtool.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    DBTool *gr = new DBTool("tessst");
    Controller f(gr);
   // f.add_section("section1","classid");
   // f.add_class("Class1",3);
   // f.add_student("Student1","section1","luis","lopez");

 // f.add_lab("student1lab1","student1","recursion","1");
  //f.add_lab("student1lab1","student1","recursion","1");
    return 0;
}

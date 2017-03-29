#include <iostream>
#include "section.h"
#include "lab.h"
#include "student.h"
#include "dbtool.h"
#include "fileparser.h"
using namespace std;

int main(int argc, char *argv[])
{
    DBTool *tool = new DBTool("Sectiontable");
    Section sec(1,tool);
    sec.add_student("luis","lopez");

    FileParser f("Wheel.java");
    cout << "Hello World!" << endl;
    return 0;
}

#include <iostream>
#include "section.h"
#include "lab.h"
#include "student.h"
#include "dbtool.h"
using namespace std;

int main(int argc, char *argv[])
{
    DBTool *tool = new DBTool("Sectiontable");
    Section sec(1,tool);
    sec.add_student("luis","lopez");
    cout << "Hello World!" << endl;
    return 0;
}

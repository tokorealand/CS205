#include <iostream>
#include "section.h"
#include "lab.h"
#include "student.h"
#include "dbtool.h"
#include "commentengine.h"
using namespace std;

int main(int argc, char *argv[])
{
    DBTool *tool = new DBTool("Commenttable");
    CommentEngine sec(tool,"ctable");
    std::cout<<sec.get_comment(1);
  //  sec.add_comment("hf");
  //  std::cout<<sec.get_comment(0);

    return 0;
}

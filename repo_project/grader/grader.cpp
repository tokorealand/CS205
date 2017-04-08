#include "grader.h"

Grader::Grader()
{
tool = new DBTool("Grader");
control = new Controller(tool);
}

Grader::~Grader()
{
delete control;
delete tool;
}

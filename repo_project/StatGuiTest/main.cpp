#include <iostream>
#include "../grader/lab.h"
#include "../grader/grader.h"
#include "../grader/year.h"
#include "../grader/semester.h"
#include "../grader/component.h"
#include "../StatisticsGui/statisticsgui.h"
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

using namespace std;

/**
 * @brief gui runs
 */
TEST(StatisticsGui, run){

Grader *grad = new Grader();
StatisticsGui *sg = new StatisticsGui(0, grad);
sg->on_yearSelect_activated(QString::fromStdString("2017"));
//sg->display_years();
//string s = sg->ui->yearSelect.getSelectedText().toStdString();
//ASSERT_EQ(s, "2017");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


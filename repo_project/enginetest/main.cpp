#include <iostream>

  #include "gtest/gtest.h"

//checks to see if searching for non players returns the value of -1
//TEST(PlayerGameHistory, findemptyplayer)
//{
//    DBTool *tool = new DBTool();
//    PlayerGameHistory pgh(tool);
//    int check;
//    check=pgh.find_player_avg("luis","lopez");
//    ASSERT_EQ(check,-1);
//}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

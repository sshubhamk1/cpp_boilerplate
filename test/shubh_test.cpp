#include "gtest/gtest.h"
#include "shubh.h"

// class Shubham_Test: public ::testing::Test
// {
//     Shubham_Test()
//     {

//     }

//     ~Shubham_Test() override
//     {

//     }

//     void SetUp() override
//     {

//     }
//     void TearDown() override
//     {

//     }

// };

// TEST_F(Shubham_Test, CheckName)
// {
//     Shubham s;
//     EXPECT_EQ("empty", s.get_name());
// }

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

TEST(Shubh_test, namecheck)
{
    Shubham s("shubham",123);
    EXPECT_EQ("shubham", s.get_name());
}

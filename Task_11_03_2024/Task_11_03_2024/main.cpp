#include <gtest/gtest.h>
#include "func.h"

using namespace std;

TEST(HouseTest, Test1)
{
    vector<int> expectedResult = { 0,2 };
    vector<int> heights = { 2,1,1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test2)
{
    vector<int> expectedResult = { 2 };
    vector<int> heights = { 1,1,1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test3)
{
    vector<int> expectedResult = { 1,2 };
    vector<int> heights = { 1,2,1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test4)
{
    vector<int> expectedResult = {0,1,2};
    vector<int> heights = { 3,2,1 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test5)
{
    vector<int> expectedResult = {2};
    vector<int> heights = { 1,2,3 };
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

TEST(HouseTest, Test6)
{
    vector<int> expectedResult = {};
    vector<int> heights = {};
    ASSERT_EQ(expectedResult, getIndeces(heights));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
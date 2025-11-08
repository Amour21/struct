#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "../src/stack_min.h"


TEST(Stack_Min_STD, Empty_On_Create_Is_Empty) {
    Stack_Min<int> s;
    EXPECT_TRUE(s.empty());
}

TEST(Stack_Min_STD, Empty_On_Create_Size_Is_Zero) {
    Stack_Min<int> s;
    EXPECT_EQ(s.size(), 0u);
}

TEST(Stack_Min_STD, Push_Increases_Size) {
    Stack_Min<int> s;
    s.push(42);
    EXPECT_EQ(s.size(), 1u);
}

TEST(Stack_Min_STD, Size_Changes_Correct) {
    Stack_Min<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.size(), 3u);
}

TEST(Stack_Min_STD, Top_Is_Last_Pushed) {
    Stack_Min<int> s;
    s.push(10);
    s.push(20);
    EXPECT_EQ(s.top(), 20);
}

TEST(Stack_Min_STD, Pop_Decreases_Size) {
    Stack_Min<int> s;
    s.push(5);
    s.push(6);
    s.pop();
    EXPECT_EQ(s.size(), 1u);
}

TEST(Stack_Min_STD, Empty_After_Pop) {
    Stack_Min<int> s;
    s.push(9);
    s.pop();
    EXPECT_TRUE(s.empty());
}

TEST(Stack_Min_STD, Empty_Pop_Throws_Error) {
    Stack_Min<int> s;
    EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(Stack_Min_STD, Empty_Top_Throws_Error) {
    Stack_Min<int> s;
    EXPECT_THROW(s.top(), std::out_of_range);
}

TEST(Stack_Min_STD, Empty_After_Clear) {
    Stack_Min<int> s;
    s.push(1);
    s.clear();
    EXPECT_TRUE(s.empty());
}

TEST(Stack_Min_STD, Size_Zero_After_Clear) {
    Stack_Min<int> s;
    s.push(1);
    s.push(2);
    s.clear();
    EXPECT_EQ(s.size(), 0u);
}

TEST(Stack_Min_With_String, Push_Sets_Top) {
    Stack_Min<std::string> s;
    s.push("hello");
    EXPECT_EQ(s.top(), "hello");
}

TEST(Stack_Min_With_String, Pop_Updates_Top) {
    Stack_Min<std::string> s;
    s.push("a");
    s.push("b");
    s.pop();
    EXPECT_EQ(s.top(), "a");
}

TEST(Stack_Work, Min_Correct) {
    Stack_Min<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(24);
    s.push(0);
    EXPECT_EQ(s.getMin(), 0);
}
TEST(Stack_Work, Min_Absolute_Correct) {
    Stack_Min<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(24);
    s.push(0);
    s.pop();
    s.pop();
    s.push(-2);
    EXPECT_EQ(s.getMin(), -2);
}
TEST(Stack_Work, Min_Throw_Correct) {
    Stack_Min<int> s;
    EXPECT_THROW(s.getMin(), std::out_of_range);
}


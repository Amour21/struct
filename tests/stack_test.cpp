#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "../src/stack.h"


TEST(Stack_STD, Empty_On_Create_Is_Empty) {
    Stack<int> s;
    EXPECT_TRUE(s.empty());
}

TEST(Stack_STD, Empty_On_Create_Size_Is_Zero) {
    Stack<int> s;
    EXPECT_EQ(s.size(), 0u);
}

TEST(Stack_STD, Push_Increases_Size) {
    Stack<int> s;
    s.push(42);
    EXPECT_EQ(s.size(), 1u);
}

TEST(Stack_STD, Size_Changes_Correct) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.size(), 3u);
}

TEST(Stack_STD, Top_Is_Last_Pushed) {
    Stack<int> s;
    s.push(10);
    s.push(20);
    EXPECT_EQ(s.top(), 20);
}

TEST(Stack_STD, Pop_Decreases_Size) {
    Stack<int> s;
    s.push(5);
    s.push(6);
    s.pop();
    EXPECT_EQ(s.size(), 1u);
}

TEST(Stack_STD, Empty_After_Pop) {
    Stack<int> s;
    s.push(9);
    s.pop();
    EXPECT_TRUE(s.empty());
}

TEST(Stack_STD, Empty_Pop_Throws_Error) {
    Stack<int> s;
    EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(Stack_STD, Empty_Top_Throws_Error) {
    Stack<int> s;
    EXPECT_THROW(s.top(), std::out_of_range);
}

TEST(Stack_STD, Empty_After_Clear) {
    Stack<int> s;
    s.push(1);
    s.clear();
    EXPECT_TRUE(s.empty());
}

TEST(Stack_STD, Size_Zero_After_Clear) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.clear();
    EXPECT_EQ(s.size(), 0u);
}

TEST(Stack_With_String, Push_Sets_Top) {
    Stack<std::string> s;
    s.push("hello");
    EXPECT_EQ(s.top(), "hello");
}

TEST(Stack_With_String, Pop_Updates_Top) {
    Stack<std::string> s;
    s.push("a");
    s.push("b");
    s.pop();
    EXPECT_EQ(s.top(), "a");
}


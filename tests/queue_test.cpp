#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "../src/queue.h"

TEST(Queue_STD, Empty_On_Create_IsEmpty) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
}

TEST(Queue_STD, Empty_On_Create_Size_Is_Zero) {
    Queue<int> q;
    EXPECT_EQ(q.size(), 0u);
}

TEST(Queue_STD, Correct_Pop_Throw) {
    Queue<int> q;
    EXPECT_THROW(q.pop(), std::out_of_range);
}

TEST(Queue_STD, Correct_Front_Throw) {
    Queue<int> q;
    EXPECT_THROW(q.front(), std::out_of_range);
}

TEST(Queue_STD, Correct_Back_Throw) {
    Queue<int> q;
    EXPECT_THROW(q.back(), std::out_of_range);
}
TEST(Queue_Push, Increases_Size_From_Zero_To_One) {
    Queue<int> q;
    q.push(7);
    EXPECT_EQ(q.size(), 1u);
}

TEST(Queue_Push, Front_Is_First) {
    Queue<int> q;
    q.push(11);
    EXPECT_EQ(q.front(), 11);
}

TEST(Queue_Push, Back_Is_Last) {
    Queue<int> q;
    q.push(21);
    q.push(22);
    EXPECT_EQ(q.back(), 22);
}

TEST(Queue_Pop, Size_Decreases) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    EXPECT_EQ(q.size(), 1u);
}

TEST(Queue_Pop, Front_Updated) {
    Queue<int> q;
    q.push(100);
    q.push(200);
    q.pop();
    EXPECT_EQ(q.front(), 200);
}

TEST(Queue_Clear, Empty_After_Clear) {
    Queue<int> q(4);
    q.push(1);
    q.clear();
    EXPECT_TRUE(q.empty());
}

TEST(Queue_Clear, Size_Zero) {
    Queue<int> q(4);
    q.push(1);
    q.push(2);
    q.clear();
    EXPECT_EQ(q.size(), 0u);
}

TEST(Queue_Resize, Size_After_Many_Pushes_Is_Correct) {
    Queue<int> q(2);
    for (int i = 1; i <= 10; ++i) q.push(i);
    EXPECT_EQ(q.size(), 10u);
}

TEST(Queue_Resize, Order_Preserved) {
    Queue<int> q(2);
    for (int i = 1; i <= 10; ++i) q.push(i);
    EXPECT_EQ(q.front(), 1);
}

TEST(Queue_String, Front_Is_First) {
    Queue<std::string> q;
    q.push("a");
    EXPECT_EQ(q.front(), "a");
}

TEST(Queue_String, Back_Is_Last) {
    Queue<std::string> q;
    q.push("a");
    q.push("b");
    EXPECT_EQ(q.back(), "b");
}

TEST(Queue_String, Pop_Correct_Change_Front) {
    Queue<std::string> q;
    q.push("a");
    q.push("b");
    q.pop();
    EXPECT_EQ(q.front(), "b");
}

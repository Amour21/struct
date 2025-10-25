#include <gtest/gtest.h>
#include <vector>
#include <deque>
#include <random>
#include <algorithm>
#include <string>
#include "../src/stack.h"
#include "../src/queue.h"

#ifndef STRESS_N
#define STRESS_N 2000000
#endif
TEST(Stack_Stress, LIFO) {
    Stack<int> s;
    const int N = STRESS_N;
    std::vector<int> expected;
    expected.reserve(N);
    for (int i = 0; i < N; ++i) {
        s.push(i);
        expected.push_back(i);
    }
    for (int i = N - 1; i >= 0; --i) {
        ASSERT_EQ(s.top(), expected.back());  
        s.pop();
        expected.pop_back();
    }
    ASSERT_TRUE(s.empty());
}
TEST(Stack_Stress, Perepakovki) {
    Stack<int> s;
    const int cycles = 500;
    const int per_cycle = 1000;  
    for (int c = 0; c < cycles; ++c) {
        for (int i = 0; i < per_cycle; ++i) s.push(i);
        for (int i = 0; i < per_cycle; ++i) s.pop();
        ASSERT_EQ(s.size(), 0u);
        ASSERT_TRUE(s.empty());
    }
}
TEST(Queue_Stress, FIFO) {
    Queue<int> q(64); 
    const int N = STRESS_N;
    std::deque<int> expected;
    for (int i = 0; i < N; ++i) {
        q.push(i);
        expected.push_back(i);
    }
    while (!expected.empty()) {
        ASSERT_EQ(q.front(), expected.front());  
        q.pop();
        expected.pop_front();
    }
    ASSERT_TRUE(q.empty());
}
TEST(Queue_Stress, Perepakovki) {
    Queue<int> q(4);  
    const int rounds = 20000;
    const int batch = 10;
    int val = 0;
    std::deque<int> mirror;
    for (int r = 0; r < rounds; ++r) {
        for (int b = 0; b < batch; ++b) {
            q.push(val);
            mirror.push_back(val);
            ++val;
        }
        for (int b = 0; b < batch / 2; ++b) {
            ASSERT_EQ(q.front(), mirror.front());   
            q.pop();
            mirror.pop_front();
        }
    }
    while (!mirror.empty()) {
        ASSERT_EQ(q.front(), mirror.front());
        q.pop();
        mirror.pop_front();
    }
    ASSERT_TRUE(q.empty());
}
#include <gtest/gtest.h>
#include "../src/task.h" 
#include <vector>

TEST(Task, empty_list_no_cycle) {
    Node* first = nullptr;
    bool res = has_cycle(first);
    EXPECT_FALSE(res);
}

TEST(Task, single_lis_no_cycle) {
    Node* first = build_list({ 1 });
    bool res = has_cycle(first);
    EXPECT_FALSE(res);
    free_list(first);
}

TEST(Task, single_list_self_cycle) {
    Node* first = build_list_with_cycle({ 1 }, 0);  
    bool res = has_cycle(first);
    EXPECT_TRUE(res);
    free_list(first);
}

TEST(Task, small_no_cycle) {
    Node* first = build_list({ 1,2,3,4,5 });
    bool res = has_cycle(first);
    EXPECT_FALSE(res);
    free_list(first);
}

TEST(Task, cycle_at_first) {
    Node* first = build_list_with_cycle({ 10,20,30,40 }, 0);  
    bool res = has_cycle(first);
    EXPECT_TRUE(res);
    free_list(first);
}

TEST(Task, cycle_in_middle) {
    const int n = 80;
    std::vector<int> vals;
    for (int i = 0; i < n; ++i) vals.push_back(i + 1);
    int entry = 34;  
    Node* first = build_list_with_cycle(vals, entry);
    bool res = has_cycle(first);
    EXPECT_TRUE(res);
    free_list(first);
}

TEST(Task, large_list_no_cycle) {
    const int N = 2000;
    std::vector<int> vals;
    vals.reserve(N);
    for (int i = 0; i < N; ++i) vals.push_back(i);
    Node* first = build_list(vals);
    bool res = has_cycle(first);
    EXPECT_FALSE(res);
    free_list(first);
}

TEST(Task, large_list_with_cycle) {
    const int N = 2000;
    std::vector<int> vals;
    vals.reserve(N);
    for (int i = 0; i < N; ++i) vals.push_back(i);
    int entry = 1542;
    Node* first = build_list_with_cycle(vals, entry);
    bool res = has_cycle(first);
    EXPECT_TRUE(res);
    free_list(first);
}
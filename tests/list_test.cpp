#include <gtest/gtest.h>
#include "../src/list.h"   


TEST(Forward_List, can_create_correct_size_list) {
    ForwardList<int> L(5, 42);
    EXPECT_EQ(L.size(), 5u);
}

TEST(Forward_List, create_list_with_correct_value) {
    ForwardList<int> L(30, 7);
    EXPECT_EQ(L[23], 7);
}

TEST(Forward_List, push_front_increases_size_by_one) {
    ForwardList<int> L;
    L.push_front(10);
    EXPECT_EQ(L.size(), 1u);
}

TEST(Forward_List, push_front_return_correct_iterator) {
    ForwardList<int> L;
    auto it = L.push_front(5);
    EXPECT_EQ(*it, 5);
}

TEST(Forward_List, push_front_insert_element_in_correct_order) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2);
    EXPECT_EQ(L[0], 2);
}

TEST(Forward_List, insert_after_inserts_after_given_iterator) {
    ForwardList<int> L;
    auto it = L.push_front(1);
    L.insert_after(it, 2);
    auto it2 = it; ++it2;
    EXPECT_EQ(*it2, 2);
}

TEST(Forward_List, insert_after_end_throw) {
    ForwardList<int> L;
    auto it_end = L.end();
    EXPECT_THROW(L.insert_after(it_end, 3), std::out_of_range);
}

TEST(Forward_List, erase_after_removes_element_and_returns_next) {
    ForwardList<int> L;
    auto a = L.push_front(1);
    auto b = L.insert_after(a, 2);
    auto after = L.erase_after(a);
    EXPECT_EQ(after, L.end());
    EXPECT_EQ(L.size(), 1u);
}

TEST(Forward_List, erase_front_correct_work) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2);
    L.erase_front();
    EXPECT_EQ(L[0], 1);
    EXPECT_EQ(L.size(), 1u);
}

TEST(Forward_List, erase_on_empty_working_correct) {
    ForwardList<int> L;
    auto it = L.erase_front();
    EXPECT_EQ(it, L.end());
    EXPECT_TRUE(L.empty());
}

TEST(Forward_List, access_out_of_range_throw_correct) {
    ForwardList<int> L;
    L.push_front(1);
    EXPECT_THROW(L[5], std::out_of_range);
}

TEST(Forward_List, clear_work_correct) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2);
    L.clear();
    EXPECT_TRUE(L.empty());
    EXPECT_EQ(L.size(), 0u);
}

TEST(Forward_List, find_correct_working) {
    ForwardList<int> L;
    L.push_front(3);
    L.push_front(4); 
    auto it = L.find(3);
    EXPECT_NE(it, L.end());
    EXPECT_EQ(*it, 3);
}

TEST(Forward_List, find_return_end_when_element_not_in_list) {
    ForwardList<int> L;
    L.push_front(1);
    auto it = L.find(99);
    EXPECT_EQ(it, L.end());
}

TEST(Forward_List, begin_end_on_empty_are_equal) {
    ForwardList<int> L;
    EXPECT_EQ(L.begin(), L.end());
}

TEST(Forward_List, iterator_prefix_and_postfix_work) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2);
    auto it = L.begin();
    ++it;
    EXPECT_EQ(*it, 1);
    it = L.begin();
    auto old = it++;
    EXPECT_EQ(*old, 2);
    EXPECT_EQ(*it, 1);
}

TEST(Forward_List, iterator_arrow_operator_accesses_member) {
    struct S { int x; };
    ForwardList<S> L;
    L.push_front(S{ 7 });
    auto it = L.begin();
    EXPECT_EQ(it->x, 7);
}

TEST(Forward_List, range_for_iterates_all_elements) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2);
    L.push_front(3); 
    std::vector<int> out;
    for (auto& v : L) out.push_back(v);
    EXPECT_EQ(out.size(), 3u);
    EXPECT_EQ(out[0], 3);
    EXPECT_EQ(out[1], 2);
    EXPECT_EQ(out[2], 1);
}

TEST(Forward_List, copy_constructor_deep_copies_nodes) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2); 
    ForwardList<int> C(L);  
    L.erase_front();  
    EXPECT_EQ(C.size(), 2u);
    EXPECT_EQ(C[0], 2);
}

TEST(Forward_List, move_constructor_transfers_ownership) {
    ForwardList<int> L;
    L.push_front(1);
    L.push_front(2);
    ForwardList<int> M(std::move(L));
    EXPECT_EQ(M.size(), 2u);
    EXPECT_TRUE(L.empty());
}

TEST(Forward_List, copy_assignment_overwrites_target_with_deep_copy) {
    ForwardList<int> A;
    A.push_front(1);
    ForwardList<int> B;
    B.push_front(2);
    B = A;  
    EXPECT_EQ(B.size(), 1u);
    EXPECT_EQ(B[0], 1);
}

TEST(Forward_List, move_assignment_transfers_and_empties_source) {
    ForwardList<int> A;
    A.push_front(9);
    ForwardList<int> B;
    B = std::move(A);
    EXPECT_EQ(B.size(), 1u);
    EXPECT_TRUE(A.empty());
}

TEST(Forward_List, multiple_inserts_and_erases_maintain_order_and_size) {
    ForwardList<int> L;
    auto a = L.push_front(1);
    auto b = L.push_front(2);
    L.insert_after(b, 3);
    EXPECT_EQ(L.size(), 3u);
    auto it = L.find(3);
    EXPECT_NE(it, L.end());
    L.erase_after(b);
    EXPECT_EQ(L.size(), 2u);
    EXPECT_EQ(L[0], 2);
    EXPECT_EQ(L[1], 1);
}

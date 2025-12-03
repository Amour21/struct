#pragma once
#include <vector>
#include <cstddef>

struct Node {
    int val;
    Node* next = nullptr;
    explicit Node(int v) : val(v), next(nullptr) {}
};
inline Node* build_list(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* first = new Node(vals[0]);
    Node* cur = first;
    for (std::size_t i = 1; i < vals.size(); ++i) {
        cur->next = new Node(vals[i]);
        cur = cur->next;
    }
    return first;
}
inline Node* build_list_with_cycle(const std::vector<int>& vals, int pos) {
    Node* first = build_list(vals);
    if (!first) return nullptr;
    if (pos < 0) return first;

    Node* cur = first;
    Node* target = nullptr;
    int idx = 0;
    while (cur->next) {
        if (idx == pos) target = cur;
        cur = cur->next;
        ++idx;
    }
    if (idx == pos) target = cur;  
    if (target) cur->next = target;  
    return first;
}
inline bool has_cycle(Node* first) {
    if (!first) return false;
    Node* slow = first;
    Node* fast = first;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

inline Node* find_cycle_start(Node* first) {
    if (!first) return nullptr;
    Node* slow = first;
    Node* fast = first;
    bool found = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return nullptr;
    slow = first;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

inline void free_list(Node* first) {
    if (!first) return;
    Node* start = find_cycle_start(first);
    if (start) {
        Node* p = start;
        while (p->next != start) p = p->next;
        p->next = nullptr;
    }
    Node* cur = first;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}
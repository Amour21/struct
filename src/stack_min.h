#include <vector>
#include <cstddef>
#include <stdexcept>
#include <algorithm> 
#include <utility>

template <typename T, template <typename, typename = std::allocator<T>> class Container = std::vector>
class Stack_Min {
    Container<T> data;   
    Container<T> mins;   // стек текущих минимумов (mins.back() = min для текущего состояния)

public:
    void push(const T& el) {
        data.push_back(el);
        if (mins.empty()) mins.push_back(el);
        else mins.push_back(std::min(el, mins.back()));
    }
    void push(T&& el) {
        data.push_back(std::move(el));
        const T& current = data.back(); 
        if (mins.empty()) mins.push_back(current);
        else mins.push_back(std::min(current, mins.back()));
    }
    void pop() {
        if (!data.empty()) {
            data.pop_back();
            mins.pop_back();
        }
        else {
            throw std::out_of_range("Stack is empty");
        }
    }
    T top() const {
        if (!data.empty())
            return data.back();
        else
            throw std::out_of_range("Stack is empty");
    }
    T getMin() const {
        if (!mins.empty())
            return mins.back();
        else
            throw std::out_of_range("Stack is empty");
    }

    size_t size() const { return data.size(); }
    void clear() { data.clear(); mins.clear(); }
    bool empty() const { return data.empty(); }
};

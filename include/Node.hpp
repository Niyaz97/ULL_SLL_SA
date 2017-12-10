#ifndef ULL_SLL_SA_NODE_HPP
#define ULL_SLL_SA_NODE_HPP

#include <iostream>
#include <functional>
#include <memory>

class array{
public:
    explicit array(size_t c);
    ~array();

    auto insert(int key, int data, std::function<bool(const int&, const int&)> comparator) -> void;
    auto remove(int key) -> bool;
    auto search(int key) -> int;
    auto print() -> void;

    auto insert_idx(int key, std::function<bool(const int&, const int&)> comparator) -> size_t;
    auto idx(int key, size_t index, std::function<bool(const int&, const int&)> comparator) -> size_t;

    auto full() -> bool;

    friend class unrolledlist;

private:
    struct node{
        int key_;
        int data_;
    };

    node* arr_;
    std::shared_ptr<array> prev_;
    std::shared_ptr<array> next_;

    size_t count_;
    size_t capacity_;

    std::function<bool(const int&, const int&)> comparator;

};



#endif //ULL_SLL_SA_NODE_HPP

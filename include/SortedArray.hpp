#ifndef ULL_SLL_SA_SORTEDARRAY_HPP
#define ULL_SLL_SA_SORTEDARRAY_HPP


#include <iostream>
#include <functional>


class sortedarray{
public:
    sortedarray();
    ~sortedarray();

    auto insert(int key, int data) -> void;
    auto remove(int key) -> void;
    auto print() -> void;
    auto binarysearch(int key) -> size_t ;
    auto findmin() -> int;
    auto findmax() -> int;
    
    auto insert_idx(int key) -> size_t;
    auto idx(int key,  size_t index) -> size_t;
    auto resize() -> void;
    auto count() -> size_t;

private:
    struct node{
        int key_;
        int data_;
    };

    node* arr_;
    size_t count_;
    size_t capacity_;

    std::function<bool(const int&, const int&)> comparator;
};






#endif //ULL_SLL_SA_SORTEDARRAY_HPP


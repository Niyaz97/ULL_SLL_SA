#ifndef ULL_SLL_SA_SORTEDARRAY_HPP
#define ULL_SLL_SA_SORTEDARRAY_HPP


#include <iostream>
#include <functional>
#include <fstream>

class sortedarray{
public:
    sortedarray();
    ~sortedarray();

    auto insert(int key, int data) -> void;
    auto remove(int key) -> void;
    auto print(std::ofstream& fout) -> void;
    auto search(int key) -> std::pair<int, int>;
//    auto search(int key) -> int;
    auto binarysearch(int key) -> size_t ;
    auto findmin() -> std::pair<int, int>;
    auto findmax() -> std::pair<int, int>;
    
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


#ifndef ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#define ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#include <iostream>


class sortedlist{
public:
    sortedlist();
    ~sortedlist();
    auto insert(int key, int data) -> void;
    auto remove(int key) -> void;
    auto print() -> void;
    auto search(int key) -> int;
    auto findmin() -> int;
    auto findmax() -> int;

    auto count() -> size_t;

private:
    struct node{
        int   address_;
        int   data_;
        node* next_;
        node* prev_;
    };

    node* head_;
    node* tail_;

    size_t count_; // счетчик количества элементов в списке
};

#endif //ULL_SLL_SA_SORTEDLINKEDLIST_HPP
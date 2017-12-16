#ifndef ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#define ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#include <iostream>
#include <fstream>

class sortedlist{
public:
    sortedlist();
    ~sortedlist();
    auto insert(int key, int data) -> void;
    auto remove(int key) -> void;
    auto print(std::ofstream& fout) -> void;
    auto search(int key) -> std::pair<int, int>;
    auto findmin() -> std::pair<int, int>;
    auto findmax() -> std::pair<int, int>;

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
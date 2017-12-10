#ifndef ULL_SLL_SA_UNROLLEDLINKEDLIST_HPP
#define ULL_SLL_SA_UNROLLEDLINKEDLIST_HPP

#include "Node.hpp"

class unrolledlist{
public:
    unrolledlist();
    ~unrolledlist();
    auto insert(int key, int data) -> void;
    auto remove(int key) -> void;
    auto search(int key) -> int;
    auto print() -> void;
    auto findmin() -> int;
    auto findmax() -> int;

    auto count() -> size_t;

private:

    size_t count_;
    size_t size_;
    std::shared_ptr<array> head_;
    std::shared_ptr<array> tail_;
    std::function<bool(const int&, const int&)> comparator;
};

#endif //ULL_SLL_SA_UNROLLEDLINKEDLIST_HPP

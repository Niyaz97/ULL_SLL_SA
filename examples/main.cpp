#include "SortedLinkedList.hpp"
//#include "SortedArray.hpp"


int main() {
//    Array<int> a;
//    a.setLength(10);
//    a.operator[](1);
    list l;
    l.push(10, 12);
    l.push(2, 30);
    l.push(4,612);
    l.push(1,13);
    l.pop(2);
    l.push(321,612);
    l.print();
    l.search(10);
    std::cout << std::endl;
    std::cout << l.findmin();
    std::cout << std::endl;
    std::cout << l.findmax();
}
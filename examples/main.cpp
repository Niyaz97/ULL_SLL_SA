//#include "SortedLinkedList.cpp"
//#include "SortedArray.hpp"
//#include "Node.hpp"
//#include "UnrolledLinkedList.hpp"
#include <iostream>
#include "SortedLinkedList.hpp"

int main() {
        try {
//            int* a;
//            unrolledlist u(412);
//            u.insert(a,0,2);
//            u.insert(a,1,52);
//            u.insert(a,2,512);
//            u.insert(a,3,2);
//            u.insert(a,4,52);
//            u.insert(a,5,512);
//            u.print();

//            linked_node* l;
//            ull* u;
//            insert_unrolled(4, u);


                sortedlist l;
                l.insert(4, 612);
                l.insert(1, 13);
                l.insert(2, 30);
                l.insert(-10, 12);
                l.print();

                l.remove(2);
                l.insert(321, 612);
                l.insert(23412, 4232);
                l.print();
                l.remove(321);
//                l.search(10);
                l.findmin();
                l.findmax();
//    sll();
//            SortedArrays s;
//            s.insert(5131);
//            s.insert(21);
//            s.insert(412);
//            s.insert(4);
//            s.insert(124);
//            s.insert(2175424);
//            s.insert(313);
//    s.print();
//    s.remove(1);
//
//    SortedArrays s;
//    s.insert(524);
//    s.insert(8);
//    s.insert(0);
//    s.print();
        }  catch (std::logic_error& e) {
                std::cerr << e.what() << std::endl;
        }
}
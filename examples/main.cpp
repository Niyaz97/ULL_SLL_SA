//#include "SortedArray.hpp"
//#include "Node.hpp"
//#include "UnrolledLinkedList.hpp"

#include "SortedLinkedList.hpp"
#include <fstream>
#include <chrono>


typedef std::chrono::high_resolution_clock::time_point ExecTime;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

auto add_time = 0, del_time = 0, search_time = 0, min_time = 0, max_time = 0;

void sll(){
    sortedlist list;
    std::string command, key, data;
    bool flag = true;
    std::ifstream fin("test.txt");
    if (fin.fail())
        throw std::logic_error("File not found");
    else {
        freopen("result.txt", "w", stdout);
        while (!fin.eof()) {
            std::getline(fin, command);
            if (command.find("add") != std::string::npos) {
                if (command[3] == ' ') {
                    for (int i = 4; i < command.length(); i++) {
                        if (command[i] != ' ' && flag)
                            key += command[i];
                        else if (command[i] == ' ')
                            flag = false;
                        else data += command[i];
                    }
                    if (!key.empty() && !data.empty()) {
                        ExecTime t1 = timeNow();
                        list.insert(atoi(key.c_str()), atoi(data.c_str()));
                        add_time = duration(timeNow() - t1);
                    }
                    else throw std::logic_error("Error while adding");
                } else throw std::logic_error("Error while adding");
            }

            if (command.find("delete") != std::string::npos) {
                if (command[6] == ' ') {
                    for (int i = 7; i < command.length(); i++) {
                        key += command[i];
                    }
                    ExecTime t2 = timeNow();
                    list.remove(atoi(key.c_str()));
                    del_time = duration(timeNow() - t2);
                } else throw std::logic_error("Error while deleting");
            }
            if (command.find("print") != std::string::npos)
                list.print();
            if (command.find("search") != std::string::npos) {
                if (command[6] == ' ') {
                    for (int i = 7; i < command.length(); i++) {
                        key += command[i];
                    }
                    ExecTime t3 = timeNow();
                    list.search(atoi(key.c_str()));
                    search_time = duration(timeNow() - t3);
                } else throw std::logic_error("Error while searching");
            }
            if (command.find("min") != std::string::npos) {
                ExecTime t4 = timeNow();
                list.findmin();
                auto min_time = duration(timeNow() - t4);
            }
            if (command.find("max") != std::string::npos) {
                ExecTime t5 = timeNow();
                list.findmax();
                max_time = duration(timeNow() - t5);
            }
            if (!key.empty()) key.clear();
            if (!data.empty()) data.clear();
            flag = true;
        }
        auto result_time = add_time + del_time + search_time + min_time + max_time;
        std::cout << "Sorted Linked List: " << result_time;
        fclose(stdout);
    }
}


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
//
//                COP3530::CDAL<int> ul;
//                ul.insert(31,0);
//                ul.insert(523,1);
//                ul.insert(512,2);
//                ul.insert(412243,3);
//                ul.insert(31,0);
//                ul.insert(523,1);
//                ul.insert(512,2);
//                ul.insert(412243,3);
//                ul.print(std::cout);
//                sortedlist l;
//                l.insert(4, 612);
//                l.insert(1, 13);
//                l.insert(2, 30);
//                l.insert(-10, 12);
//                l.print();
//
//                l.remove(2);
//                l.insert(321, 612);
//                l.insert(23412, 4232);
//                l.print();
//                l.remove(321);
////                l.search(10);
//                l.findmin();
//                l.findmax();




    sll();
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
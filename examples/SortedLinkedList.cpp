#include "../include/SortedLinkedList.hpp"
#include <fstream>
#include <chrono>


typedef std::chrono::high_resolution_clock::time_point ExecTime;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

auto add_time = 0, del_time = 0, search_time = 0, min_time = 0, max_time = 0;

void sll(){
    try {
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
    } catch (std::logic_error& e) {
    std::cerr << e.what() << std::endl;
    }
}
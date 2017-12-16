#include "SortedArray.hpp"
#include "UnrolledLinkedList.hpp"
#include "SortedLinkedList.hpp"
#include <fstream>
#include <chrono>


typedef std::chrono::high_resolution_clock::time_point ExecTime;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

int main(int argc, char* argv[]) {
        try {
            if(argc != 3){
                throw std::logic_error("Wrong number of arguments");
            }

            std::string command, key, data;
            bool flag = true;
            std::ifstream fin(argv[1]);
            if(!fin.is_open()){
                throw std::logic_error("File not found");
            }

            std::ofstream fout(argv[2]);

            auto result_time = 0;
            int ds_type = 0;

            sortedarray sa;
            sortedlist sll;
            unrolledlist ull;
            ExecTime start = timeNow();
            while(!fin.eof()){
                auto add_time = 0, del_time = 0, search_time = 0, min_time = 0, max_time = 0;
                std::getline(fin, command);

                if(command == "sortedarray")
                    ds_type = 1;
                else if(command == "sortedlinkedlist")
                    ds_type = 2;
                else if(command == "unrolledlinkedlist")
                    ds_type = 3;
                else if(ds_type == 0)
                    throw std::logic_error("Data structure is not specified");

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
                            if(ds_type == 1)
                                sa.insert(atoi(key.c_str()), atoi(data.c_str()));

                            if(ds_type == 2)
                                sll.insert(atoi(key.c_str()), atoi(data.c_str()));

                            if(ds_type == 3)
                                ull.insert(atoi(key.c_str()), atoi(data.c_str()));
                        }
                        else
                            throw std::logic_error("Error while adding (too few arguments)");
                    } else
                        throw std::logic_error("Error while adding");
                }

                if (command.find("delete") != std::string::npos) {
                    if (command[6] == ' ') {
                        for (int i = 7; i < command.length(); i++) {
                            key += command[i];
                        }
                        if(ds_type == 1)
                            sa.remove(atoi(key.c_str()));

                        if(ds_type == 2)
                            sll.remove(atoi(key.c_str()));

                        if(ds_type == 3)
                            ull.remove(atoi(key.c_str()));
                    } else
                        throw std::logic_error("Error while deleting");
                }

                if (command.find("print") != std::string::npos) {
                    if (ds_type == 1)
                        sa.print(fout);

                    if(ds_type == 2)
                        sll.print(fout);

                    if(ds_type == 3)
                        ull.print(fout);
                }

                if (command.find("search") != std::string::npos) {
                    if (command[6] == ' ') {
                        for (int i = 7; i < command.length(); i++) {
                            key += command[i];
                        }
                        int search_key = atoi(key.c_str());

                        if(ds_type == 1)
                            fout<< "(" << sa.search(search_key).first << ", " << sa.search(search_key).second << ")\n";

                        if(ds_type == 2)
                            fout<< "(" << sll.search(search_key).first << ", " << sll.search(search_key).second << ")\n";

                        if(ds_type == 3)
                            fout<< "(" << ull.search(search_key).first << ", " << ull.search(search_key).second << ")\n";
                    } else
                        throw std::logic_error("Error while searching");
                }

                if (command.find("min") != std::string::npos) {
                    if(ds_type == 1)
                        fout << "(" << sa.findmin().first << ", " << sa.findmin().second << ")\n";

                    if(ds_type == 2)
                        fout << "(" << sll.findmin().first << ", " << sll.findmin().second << ")\n";

                    if(ds_type == 3)
                        fout << "(" << ull.findmin().first << ", " << ull.findmin().second << ")\n";
                }
                if (command.find("max") != std::string::npos) {
                    if(ds_type == 1)
                        fout << "(" << sa.findmax().first  << ", " << sa.findmax().second << ")\n";

                    if(ds_type == 2)
                        fout << "(" << sll.findmax().first  << ", " << sll.findmax().second << ")\n";

                    if(ds_type == 3)
                        fout << "(" << ull.findmax().first  << ", " << ull.findmax().second << ")\n";
                }

                if (!key.empty()) key.clear();
                if (!data.empty()) data.clear();
                flag = true;
            }
            ExecTime end = timeNow();
            result_time = duration(end-start);
            fout << std::endl << "Result time: " << result_time << "ns\n";
            fin.close();
            fout.close();

        }  catch (std::logic_error& e) {
                std::cout << e.what() << std::endl;
        }

}


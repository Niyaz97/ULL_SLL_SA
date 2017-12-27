#include "SortedArray.hpp"
#include "UnrolledLinkedList.hpp"
#include "SortedLinkedList.hpp"
#include <fstream>
#include <chrono>


typedef std::chrono::high_resolution_clock::time_point ExecTime;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
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

            std::ofstream fout(argv[2], std::ios_base::app);

            float result_time = 0;
            int ds_type = 0;
            size_t arr_size;

            sortedarray sa;
            sortedlist sll;
            unrolledlist ull;

            int counter_add = 0, counter_del = 0, counter_search = 0, counter_min = 0, counter_max = 0;
            float add_result = 0, del_result = 0, search_result = 0, min_result = 0, max_result = 0;

            while(!fin.eof()){
                auto add_time = 0, del_time = 0, search_time = 0;
                float max_time = 0, min_time = 0;
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
                            ExecTime t1 = timeNow();
                            if(ds_type == 1)
                                sa.insert(atoi(key.c_str()), atoi(data.c_str()));

                            if(ds_type == 2)
                                sll.insert(atoi(key.c_str()), atoi(data.c_str()));

                            if(ds_type == 3)
                                ull.insert(atoi(key.c_str()), atoi(data.c_str()));
                            add_time = duration(timeNow() - t1);
                            counter_add++;
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
                        if(!key.empty()) {
                            ExecTime t1 = timeNow();
                            if (ds_type == 1)
                                sa.remove(atoi(key.c_str()));

                            if (ds_type == 2)
                                sll.remove(atoi(key.c_str()));

                            if (ds_type == 3)
                                ull.remove(atoi(key.c_str()));
                            del_time = duration(timeNow() - t1);
                            counter_del++;
                        }
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

                        if (!key.empty()) {
                            ExecTime t1 = timeNow();
                            if (ds_type == 1){
//                            fout<< "(" << sa.search(search_key).first << ", " << sa.search(search_key).second << ")\n";
                                sa.search(search_key).first;
                                sa.search(search_key).second;
//                                sa.search(search_key);
                            }
                            if (ds_type == 2){
//                            fout<< "(" << sll.search(search_key).first << ", " << sll.search(search_key).second << ")\n";
                                sll.search(search_key).first;
                                sll.search(search_key).second;
//                                sll.search(search_key);
                            }
                            if (ds_type == 3){
//                            fout<< "(" << ull.search(search_key).first << ", " << ull.search(search_key).second << ")\n";
                                ull.search(search_key).first;
                                ull.search(search_key).second;
                            }
                            search_time = duration(timeNow() - t1);
                            counter_search++;
                        }
                    } else
                        throw std::logic_error("Error while searching");
                }

                if (command.find("min") != std::string::npos) {
                    ExecTime t1 = timeNow();
                    if(ds_type == 1)
//                        fout << "(" << sa.findmin().first << ", " << sa.findmin().second << ")\n";
                    {sa.findmin().first;
                        sa.findmin().second;}

                    if(ds_type == 2)
//                        fout << "(" << sll.findmin().first << ", " << sll.findmin().second << ")\n";
                    {sll.findmin().first;
                        sll.findmin().second;}

                    if(ds_type == 3)
//                        fout << "(" << ull.findmin().first << ", " << ull.findmin().second << ")\n";
                    {ull.findmin().first;
                        ull.findmin().second;}
                    min_time = duration(timeNow() - t1);
                    counter_min++;
                }
                if (command.find("max") != std::string::npos) {
                    ExecTime t1 = timeNow();
                    if(ds_type == 1)
//                        fout << "(" << sa.findmax().first  << ", " << sa.findmax().second << ")\n";
                    {sa.findmax().first;
                    sa.findmax().second;}
                    if(ds_type == 2)
//                        fout << "(" << sll.findmax().first  << ", " << sll.findmax().second << ")\n";
                    {sll.findmax().first;
                        sll.findmax().second;}

                    if(ds_type == 3)
//                        fout << "(" << ull.findmax().first  << ", " << ull.findmax().second << ")\n";
                    {ull.findmax().first;
                        ull.findmax().second;}
                    max_time = duration(timeNow() - t1);
                    counter_max++;
                }

                if (!key.empty()) key.clear();
                if (!data.empty()) data.clear();
                flag = true;
                add_result += add_time;
                del_result += del_time;
                search_result += search_time;
                min_result += min_time;
                max_result += max_time;
            }

            //для тестов x_001.dat
            if(counter_add && !counter_del && !counter_search && !counter_min && !counter_max)
                fout << std::endl << "Insert time: " << add_result << "µs\n";

            //для тестов x_002.dat
            if(counter_add && counter_del && !counter_search && !counter_min && !counter_max)
                fout << std::endl << "Delete time: " << del_result << "µs\n";

            //для тестов x_003.dat
            if(counter_add && !counter_del && counter_search && !counter_min && !counter_max)
                fout << std::endl << "Search time: " << search_result << "µs\n";

            //для тестов x_004.dat
            if(counter_add && !counter_del && !counter_search && counter_min && counter_max) {
                result_time = min_result + max_result;
                fout << std::endl << "Min and Max time: " << result_time << "ns\n";
            }

            //для тестов x_005.dat
            if(counter_add && !counter_del && counter_search && counter_min && counter_max) {
                result_time = add_result + min_result + max_result + search_result;
                fout << std::endl << "Result time: " << result_time << "µs\n";
            }

            //для тестов x_006.dat
            if(counter_add && counter_del && !counter_search && counter_min && counter_max) {
                result_time = add_result + min_result + max_result + del_result;
                fout << std::endl << "Result time: " << result_time << "µs\n";
            }

            //для тестов x_007.dat
            if(counter_add && counter_del && counter_search && counter_min && counter_max) {
                result_time = add_result + min_result + max_result + del_result + search_result;
                fout << std::endl << "Result time: " << result_time << "µs\n";
            }
            //для тестов x_008.dat
            if(counter_add && counter_del && counter_search && !counter_min && !counter_max) {
                result_time = add_result + del_result;
                fout << std::endl << "Result time: " << result_time << "µs\n";
            }

            fin.close();
            fout.close();

        }  catch (std::logic_error& e) {
                std::cout << e.what() << std::endl;
        }

}


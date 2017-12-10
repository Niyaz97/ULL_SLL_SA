cmake_minimum_required(VERSION 3.2.2)
project(ULL_SLL_SA)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(SOURCE_FILES include/SortedLinkedList.hpp sources/SortedLinkedList.cpp include/SortedArray.hpp sources/SortedArray.cpp include/UnrolledLinkedList.hpp sources/UnrolledLinkedList.cpp include/Node.hpp sources/Node.cpp)
add_executable(Examples ${SOURCE_FILES} examples/main.cpp)
add_executable(Tests ${SOURCE_FILES} tests/catch.hpp tests/main.cpp tests/sll_remove.cpp tests/sll_insert.cpp tests/sll_search.cpp tests/sa_insert.cpp tests/sa_remove.cpp tests/sa_search.cpp tests/sa_minmax.cpp tests/sll_minmax.cpp tests/ull_insert.cpp tests/ull_search.cpp tests/ull_remove.cpp tests/ull_remove.cpp tests/ull_minmax.cpp)
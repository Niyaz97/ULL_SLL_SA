cmake_minimum_required(VERSION 3.8)
project(ULL_SLL_SA)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(SOURCE_FILES include/SortedLinkedList.hpp sources/SortedLinkedList.cpp)
add_executable(Examples ${SOURCE_FILES} examples/main.cpp)
add_executable(Tests ${SOURCE_FILES} tests/catch.hpp tests/main.cpp tests/sll_remove.cpp tests/sll_insert.cpp tests/sll_search.cpp)
cmake_minimum_required(VERSION 3.8)
project(ULL_SLL_SA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES examples/main.cpp include/UnrolledLinkedList.h sources/UnrolledLinkedList.cpp include/SortedLinkedList.h sources/SortedLinkedList.cpp include/SortedArray.h sources/SortedArray.cpp)
add_executable(ULL_SLL_SA ${SOURCE_FILES})
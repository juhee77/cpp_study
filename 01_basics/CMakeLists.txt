cmake_minimum_required(VERSION 4.1)
project(01_basics)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_basics_memory_hack memory_hack.cpp)
add_executable(01_basics_array_pointer array_pointer.cpp)
add_executable(01_basics_15999 19599_이진삼진탐색.cpp)
add_executable(01_basics_input_output input_output.cpp)
add_executable(01_basics_heap_memory heap_memory.cpp)
add_executable(header_test main.cpp IntArray.cpp IntArray.h)

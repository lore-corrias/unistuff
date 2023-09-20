cmake_minimum_required(VERSION 3.25)
project(merge_heap_sort C)

set(CMAKE_C_STANDARD 99)

add_executable(merge_heap_sort main.c merge_heap_sort.c merge_heap_sort.h)

cmake_minimum_required(VERSION 3.25)
project(insertion_quick_sort C)

set(CMAKE_C_STANDARD 99)

add_executable(insertion_quick_sort main.c insertion_quick_sort.c insertion_quick_sort.h)

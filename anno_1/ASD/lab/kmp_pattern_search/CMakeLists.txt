cmake_minimum_required(VERSION 3.25)
project(kmp_pattern_search C)

set(CMAKE_C_STANDARD 99)

add_executable(kmp_pattern_search main.c kmp_pattern_search.h kmp_pattern_search.c)

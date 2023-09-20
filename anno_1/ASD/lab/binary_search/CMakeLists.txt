cmake_minimum_required(VERSION 3.25)
project(binary_search C)

set(CMAKE_C_STANDARD 99)

add_executable(binary_search main.c binary_search_hotel.c binary_search_iterativa.c binary_search_ricorsiva.c)

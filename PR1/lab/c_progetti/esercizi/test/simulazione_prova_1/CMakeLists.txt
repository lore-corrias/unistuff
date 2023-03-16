cmake_minimum_required(VERSION 3.24)
project(simulazione_prova_1 C)

set(CMAKE_C_STANDARD 90)

add_executable(simulazione_prova_1 main.c)
target_link_libraries(simulazione_prova_1 m)
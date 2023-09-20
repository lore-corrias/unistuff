cmake_minimum_required(VERSION 3.25)
project(matrice_sparsa C)

set(CMAKE_C_STANDARD 99)

add_executable(matrice_sparsa main.c matrice_sparsa.c matrice_sparsa.h)

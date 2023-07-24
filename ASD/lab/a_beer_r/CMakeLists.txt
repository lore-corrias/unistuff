cmake_minimum_required(VERSION 3.25)
project(a_beer_r C)

set(CMAKE_C_STANDARD 99)

add_executable(a_beer_r main.c a_beer_r.c a_beer_r.h)

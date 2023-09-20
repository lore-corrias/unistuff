cmake_minimum_required(VERSION 3.25)
project(spotify C)

set(CMAKE_C_STANDARD 99)

add_executable(spotify main.c spotify.c spotify.h)

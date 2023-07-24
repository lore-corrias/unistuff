cmake_minimum_required(VERSION 3.25)
project(parcheggio_multipiano C)

set(CMAKE_C_STANDARD 99)

add_executable(parcheggio_multipiano main.c parcheggio_multipiano.c parcheggio_multipiano.h)

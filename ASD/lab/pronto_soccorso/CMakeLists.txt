cmake_minimum_required(VERSION 3.25)
project(pronto_soccorso C)

set(CMAKE_C_STANDARD 99)

add_executable(pronto_soccorso main.c pronto_soccorso.c pronto_soccorso.h)

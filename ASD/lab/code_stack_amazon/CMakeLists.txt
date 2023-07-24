cmake_minimum_required(VERSION 3.25)
project(code_stack_amazon C)

set(CMAKE_C_STANDARD 99)

add_executable(code_stack_amazon main.c code_stack.c code_stack.h)

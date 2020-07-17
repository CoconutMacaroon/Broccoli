cmake_minimum_required(VERSION 3.16)
project(Broccoli C)

set(CMAKE_C_STANDARD 11)

add_executable(Broccoli main.c main.h functions.c runtime.c compile.c moveFunctions.c)
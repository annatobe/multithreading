cmake_minimum_required(VERSION 4.1)
project(multithreading C)

set(CMAKE_C_STANDARD 11)

add_executable(multithreading main.c
        header.h
        parser.c
        shared.c
        utils.c)

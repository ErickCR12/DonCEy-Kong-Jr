cmake_minimum_required(VERSION 3.13)
project(C-Client C)

set(CMAKE_C_STANDARD 11)

add_executable(C-Client
        src/main.c
        src/client/Client.c)
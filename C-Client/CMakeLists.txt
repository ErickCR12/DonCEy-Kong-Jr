cmake_minimum_required(VERSION 3.13)
project(C-Client)

set(CMAKE_C_STANDARD 11)

add_executable(C-Client
        src/client/Client.c)

target_link_libraries(C-Client gtest gtest_main)
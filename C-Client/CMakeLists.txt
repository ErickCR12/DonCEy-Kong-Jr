cmake_minimum_required(VERSION 3.13)
project(C-Client C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(C-Client
        src/main.c
        src/util/var.h
        src/client/Client.c
        src/game/entities/Entity.c
        src/game/entities/Entity.h
        src/game/entities/Fruit.h
        src/game/entities/Croco.h
        src/game/entities/Platform.h
        src/game/entities/Rope.h)

target_link_libraries(C-Client ${GTK3_LIBRARIES})
    
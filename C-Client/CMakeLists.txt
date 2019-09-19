cmake_minimum_required(VERSION 3.13)
project(C-Client C)

set(CMAKE_C_STANDARD 11)

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
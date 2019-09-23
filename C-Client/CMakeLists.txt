cmake_minimum_required(VERSION 3.13)
project(C-Client C)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(C-Client
        src/main.c

        src/util/var.h
        src/res/strings_values.h
        src/util/allegrofunc.h
        src/util/allegrofunc.c

        src/client/Client.h
        src/client/Client.c
        src/json/json.h
        src/json/json.c
        src/json/json-builder.h
        src/json/json-builder.c
        src/json/cJSON.h
        src/json/cJSON.c

        src/game/entities/Entity.h
        src/game/entities/Entity.c
        src/game/entities/Entities.h
        src/game/entities/Entities.c
        src/game/entities/Fruit.h
        src/game/entities/Croco.h
        src/game/entities/Platform.h
        src/game/entities/Rope.h
        src/game/entities/Junior.h
        src/game/entities/Junior.c

        src/game/gui/GameWindow.h
        src/game/gui/GameWindow.c
        src/game/gui/CollisionHandler.c
        src/game/gui/CollisionHandler.h
        src/datastructures/LinkedList.h
        src/datastructures/Node.h
        src/datastructures/LinkedList.c
        src/datastructures/Node.c
        src/game/entities/Platform.c
        src/game/entities/Rope.c src/game/entities/Croco.c)

# build
target_link_libraries(C-Client ws2_32)
target_link_libraries(C-Client -lmingw32 -lallegro-5.0.10-monolith-md-debug)
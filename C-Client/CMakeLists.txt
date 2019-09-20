cmake_minimum_required(VERSION 3.13)
project(C-Client C)

set(CMAKE_CXX_STANDARD 11)

add_executable(C-Client
        src/main.c

        src/util/var.h
        src/res/strings_values.h

        src/client/Client.c

        src/game/entities/Entity.c
        src/game/entities/Fruit.h
        src/game/entities/Croco.h
        src/game/entities/Platform.h
        src/game/entities/Rope.h
        src/game/entities/Junior.h
        src/game/entities/Junior.c

        src/game/gui/GameWindow.h
        src/game/gui/GameWindow.c src/game/gui/CollisionHandler.c src/game/gui/CollisionHandler.h)


# build
target_link_libraries(C-Client ws2_32)
target_link_libraries(C-Client -lmingw32 -lallegro-5.0.10-monolith-md-debug)
//
// Created by José Acuña on 17/09/2019.
//

#include "game/gui/GameWindow.h"
#include <stdio.h>
#include "client/Client.h"
#include "lib/json.h"

int main(){
    // Client
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);

    Entity entity;
    entity.id = 1234;
    entity.rx = 2;
    entity.ry = 4;

    json_char *json = serialize(&entity);
    parse(json, &entity);

    // Game
    //createGameWindow();

    return 0;
}
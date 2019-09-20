//
// Created by José Acuña on 17/09/2019.
//

#include "game/gui/GameWindow.h"
#include "client/Client.h"

int main(){
    // Client
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);

    // Game
    length = 0;
    createGameWindow();

    return 0;
}
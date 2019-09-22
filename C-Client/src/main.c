//
// Created by José Acuña on 17/09/2019.
//

#include <stdlib.h>
#include <time.h>
#include "game/gui/GameWindow.h"
#include "client/Client.h"
#include "datastructures/LinkedList.h"

void socksInit() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);
    length = 0;
    srand(time(NULL));
    id = rand();
}

int main(){
    // Some Initializations
    socksInit();

    // Game
    createGameWindow();


    return 0;
}


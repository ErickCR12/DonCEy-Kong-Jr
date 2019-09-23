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
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        _exit(1);
    }
    srand((unsigned int) time(NULL));
    id = rand();
}

int main(){
    // Some Initializations
    socksInit();

    // Game
    createGameWindow();

    return 0;
}


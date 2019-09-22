//
// Created by José Acuña on 17/09/2019.
//

#include <stdlib.h>
#include <time.h>
#include "game/gui/GameWindow.h"
#include "client/Client.h"
#include "datastructures/LinkedList.h"

int main(){
    // Some Initializations
//    WSADATA wsa;
//    WSAStartup(MAKEWORD(2,2),&wsa);
//    length = 0;
//    srand(time(NULL));
//    id = rand();

    // Game
    createGameWindow();

    LinkedList *list = initializeList();

    Node *node = (Node*) malloc(sizeof(Node));


    return 0;
}
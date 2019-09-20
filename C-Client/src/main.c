//
// Created by José Acuña on 17/09/2019.
//

#include "game/gui/GameWindow.h"
#include <stdio.h>
#include "client/Client.h"

int main(){
    // Client
    start();

    // Game
    createGameWindow();

    // Client Close
    stop();

    return 0;
}
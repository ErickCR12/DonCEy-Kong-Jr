//
// Created by José Acuña on 17/09/2019.
//

#include "game/gui/GameWindow.h"
#include <stdio.h>
#include "client/Client.h"

int main(){
    createGameWindow();

    # Client
    start();

    char mess[] = "HI";
    message(mess);
    sleep(2);
    stop();

    return 0;
}
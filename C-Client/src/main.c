//
// Created by José Acuña on 17/09/2019.
//

#include <stdio.h>
#include "client/Client.h"

int main() {

    start();

    char message[] = "exit";
    sendMessage(message);
    stop();

    return 0;
}
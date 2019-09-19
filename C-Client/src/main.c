//
// Created by José Acuña on 17/09/2019.
//

#include <stdio.h>
#include "client/Client.h"

int main() {
    printf("Hello, World!\n");

    start();

    char message[] = "Hello";
    sendMessage(message);

    return 0;
}
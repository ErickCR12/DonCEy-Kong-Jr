//
// Created by José Acuña on 17/09/2019.
//

#include <stdio.h>
#include "client/Client.h"

int main() {

    start();

    char mess[] = "HI";
    message(mess);

    sleep(2);
    stop();

    return 0;
}
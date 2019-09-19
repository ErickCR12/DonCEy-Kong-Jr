//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_JUNIOR_H
#define C_CLIENT_JUNIOR_H

#include "Entity.h"

typedef struct Junior Junior;

struct Junior {
    Entity *entity;
};

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
void moveJrDown(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
#endif //C_CLIENT_JUNIOR_H
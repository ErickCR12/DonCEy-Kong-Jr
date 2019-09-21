//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_JUNIOR_H
#define C_CLIENT_JUNIOR_H

#include "Entity.h"
#include "Platform.h"
#include "Rope.h"

typedef struct Junior Junior;

struct Junior {
    Entity *entity;
};

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
int moveJrDown(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, Platform **platforms, Rope **ropes);
int moveJrUp(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, int jumping,
             Platform **platforms, Rope **ropes);
int jrJump(Junior *junior, float *jumpCount);
int jrGravity(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, Platform **platforms, Rope **ropes);

#endif //C_CLIENT_JUNIOR_H

//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_JUNIOR_H
#define C_CLIENT_JUNIOR_H

#include "Entity.h"
#include "Platform.h"
#include "Rope.h"
#include "../../util/allegrofunc.h"
#include "../../datastructures/LinkedList.h"

typedef struct Junior Junior;

struct Junior {
    Entity *entity;
    ALLEGRO_BITMAP *notMoving[1];
    ALLEGRO_BITMAP *movingLeft[3];
    ALLEGRO_BITMAP *movingRight[3];
    ALLEGRO_BITMAP *jumpingLeft[1];
    ALLEGRO_BITMAP *jumpingRight[1];
    ALLEGRO_BITMAP *ropeRight[2];
    ALLEGRO_BITMAP *ropeLeft[2];
    ALLEGRO_BITMAP *rope[1];
    int xState; // [-1, 0, 1] => [left, static, right]
    int yState; // [-1, 0, 1, 2] => [falling, platform, jumping, rope]
    int animationIndex;
    int animationTimer;
};

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);
int moveJrDown(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, Platform **platforms, Rope **ropes);
int moveJrUp(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, int jumping,
             Platform **platforms, Rope **ropes);
int jrJump(Junior *junior, float *jumpCount);
int jrGravity(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, Platform **platforms, Rope **ropes);

void notMov(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState);

void animate(Junior *);
void setAnimation(Junior *, ALLEGRO_BITMAP **, int);

void loadBitMaps(Junior *);
#endif //C_CLIENT_JUNIOR_H

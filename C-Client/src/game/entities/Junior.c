//
// Created by Erick Barrantes on 9/19/2019.
//
#include "Junior.h"
#include <stdio.h>

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT ))
        junior->entity->x += MOV_SPEED;
}

void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if (al_key_down(&keyState, ALLEGRO_KEY_LEFT ))
        junior->entity->x -= MOV_SPEED;
}

void moveJrDown(Junior *junior, Platform *platform){
    if (!isCollidingWithPlatform(junior, platform))
        junior->entity->y += MOV_SPEED;
}

int isCollidingWithPlatform(Junior *junior, Platform *platform){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    float xPlatform = platform->entity->x;
    float yPlatform = platform->entity->y;
    if(xJr <= (xPlatform + platform->width) && xJr >= xPlatform && yJr >= (yPlatform - 15) && yJr <= (yPlatform + 15))
        return TRUE;
    return FALSE;
}
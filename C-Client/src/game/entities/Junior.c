//
// Created by Erick Barrantes on 9/19/2019.
//
#include "Junior.h"
#include "../gui/CollisionHandler.h"

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT ))

        junior->entity->x += MOV_SPEED;
}

void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if (al_key_down(&keyState, ALLEGRO_KEY_LEFT ))
        junior->entity->x -= MOV_SPEED;
}

void moveJrDown(Junior *junior, Platform **platforms){
    if (!isCollidingWithPlatform(junior, platforms))
        junior->entity->y += MOV_SPEED;
}

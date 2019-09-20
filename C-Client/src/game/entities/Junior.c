//
// Created by Erick Barrantes on 9/19/2019.
//
#include "Junior.h"
#include "../gui/CollisionHandler.h"
#include <stdio.h>

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT ))

        junior->entity->x += MOV_SPEED;
}

void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if (al_key_down(&keyState, ALLEGRO_KEY_LEFT ))
        junior->entity->x -= MOV_SPEED;
}

int moveJrDown(Junior *junior, Platform **platforms){
    if (!isCollidingWithPlatform(junior, platforms)) {
        junior->entity->y += MOV_SPEED;
        return TRUE;
    }return FALSE;
}

int moveJrUp(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, int jumping,
             Platform **platforms, Rope **ropes){
    if(isCollidingWithRope(junior, ropes))
        printf("AAAA\n");
    if(!jumping) {
        if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
            junior->entity->y -= MOV_SPEED;
            *jumpCount += MOV_SPEED;
            return TRUE;
        }
    }else{
        int falling = TRUE;
        if(*jumpCount < JUMP_HEIGHT) {
            junior->entity->y -= MOV_SPEED;
            *jumpCount += MOV_SPEED;
        }else
            falling = moveJrDown(junior, platforms);

        if(!falling){
            *jumpCount = 0;
            return FALSE;
        }
    }
}

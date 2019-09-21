//
// Created by Erick Barrantes on 9/19/2019.
//
#include "Junior.h"
#include "../gui/CollisionHandler.h"
#include <stdio.h>

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if((junior->entity->x + JR_WIDTH) >= GW_WIDTH) return;
    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT ))

        junior->entity->x += MOV_SPEED;
}

void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if(junior->entity->x <= 0) return;
    if (al_key_down(&keyState, ALLEGRO_KEY_LEFT ))
        junior->entity->x -= MOV_SPEED;
}

int moveJrDown(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, Platform **platforms, Rope **ropes){
    if(isCollidingWithRope(junior, ropes)) {
        if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
            junior->entity->y += CLIMBING_SPEED;
    }else if (!isCollidingWithPlatform(junior, platforms)){
        junior->entity->y += MOV_SPEED;
        return TRUE;
    }return FALSE;
}

int moveJrUp(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, int jumping,
             Platform **platforms, Rope **ropes){
    if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
        if (isCollidingWithRope(junior, ropes))
            junior->entity->y -= CLIMBING_SPEED;
        else if (!jumping)
            return jrJump(junior, jumpCount);
        else
            return jrGravity(junior, keyState, jumpCount, platforms, ropes);
    }
}

int jrJump(Junior *junior, float *jumpCount){
    junior->entity->y -= MOV_SPEED;
    *jumpCount += MOV_SPEED;
    return TRUE;
}

int jrGravity(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, Platform **platforms, Rope **ropes){
    int falling = TRUE;
    if (*jumpCount < JUMP_HEIGHT) {
        junior->entity->y -= MOV_SPEED;
        *jumpCount += MOV_SPEED;
    } else
        falling = moveJrDown(junior, keyState, platforms, ropes);
    if (!falling) {
        *jumpCount = 0;
        return FALSE;
    }
}



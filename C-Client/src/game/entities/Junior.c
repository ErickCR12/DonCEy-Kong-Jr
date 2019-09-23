//
// Created by Erick Barrantes on 9/19/2019.
//
#include "Junior.h"
#include "../gui/CollisionHandler.h"
#include <stdio.h>

void moveJrRight(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if((junior->entity->x + JR_WIDTH) >= GW_WIDTH) return;
    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT )) {
        junior->xState = 1;
        junior->entity->x += MOV_SPEED;
    }
}

void moveJrLeft(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState){
    if(junior->entity->x <= 0) return;
    if (al_key_down(&keyState, ALLEGRO_KEY_LEFT )) {
        junior->xState = -1;
        junior->entity->x -= MOV_SPEED;
    }
}

int moveJrDown(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, Platform **platforms, Rope **ropes){
    if(isCollidingWithRope(junior, ropes)) {
        if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
            junior->entity->y += CLIMBING_DOWN_SPEED;
            junior->yState = 2;
        }
    }else if (!isCollidingWithPlatform(junior->entity, platforms)){
        junior->entity->y += GRAV_SPEED;
        junior->yState = -1;
        return TRUE;
    }return FALSE;
}

int moveJrUp(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, int jumping,
             Platform **platforms, Rope **ropes){
    if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
        if (isCollidingWithRope(junior, ropes)) {
            junior->entity->y -= CLIMBING_UP_SPEED;
            junior->yState = 2;
        }
        else if (!jumping)
            return jrJump(junior, jumpCount);
        else
            return jrGravity(junior, keyState, jumpCount, platforms, ropes);
    }
    if(isCollidingWithPlatform(junior->entity, platforms)) {
        junior->yState = 0;
        *jumpCount = 0;
    }
}

void notMov(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState) {
    if (!al_key_down(&keyState, ALLEGRO_KEY_LEFT)
    && !al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
        junior->xState = 0;
}

int jrJump(Junior *junior, float *jumpCount){
    junior->yState = 1;
    junior->entity->y -= MOV_SPEED;
    *jumpCount += MOV_SPEED;
    return TRUE;
}

int jrGravity(Junior *junior, ALLEGRO_KEYBOARD_STATE keyState, float *jumpCount, Platform **platforms, Rope **ropes){
    int falling = TRUE;
    if (*jumpCount < JUMP_HEIGHT) {
        junior->entity->y -= MOV_SPEED;
        junior->yState = 1;
        *jumpCount += MOV_SPEED;
    } else
        falling = moveJrDown(junior, keyState, platforms, ropes);
    if (!falling) {
        *jumpCount = 0;
        return FALSE;
    }
}

void animate(Junior *junior) {
    junior->animationTimer--;
    // OnRope
    if (junior->yState == 2) {
        if (junior->xState == 1) setAnimation(junior, junior->ropeRight, 2);
        else if (junior->xState == -1) setAnimation(junior, junior->ropeLeft, 2);
        else if (junior->xState == 0) setAnimation(junior, junior->ropeRight, 2);
    }
    // Jumping or Falling
    else if (junior->yState == 1 || junior->yState == -1) {
        if (junior->xState == 1 |
            junior->xState == 0) setAnimation(junior, junior->jumpingRight, 1);
        else if (junior->xState == -1) setAnimation(junior, junior->jumpingLeft, 1);
    }
    // Moving
    else if (junior->yState == 0) {
        if (junior->xState == 1) setAnimation(junior, junior->movingRight, 3);
        else if (junior->xState == -1) setAnimation(junior, junior->movingLeft, 3);
        else if (junior->xState == 0) setAnimation(junior, junior->notMoving, 1);
    }
}

void setAnimation(Junior *junior, ALLEGRO_BITMAP **array, int length) {
    if (junior->animationTimer <= 0) {
        junior->animationIndex = (junior->animationIndex + 1) % length;
        junior->animationTimer = JR_ANIM_TIME;
        junior->entity->bitmap = array[junior->animationIndex];
    }
}

void loadBitMaps(Junior *junior) {

    junior->movingLeft[0] = loadBitMap("../sprites/jr/mvl0.png");
    junior->movingLeft[1] = loadBitMap("../sprites/jr/mvl1.png");
    junior->movingLeft[2] = loadBitMap("../sprites/jr/mvl2.png");

    junior->movingRight[0] = loadBitMap("../sprites/jr/mvr0.png");
    junior->movingRight[1] = loadBitMap("../sprites/jr/mvr1.png");
    junior->movingRight[2] = loadBitMap("../sprites/jr/mvr2.png");

    junior->notMoving[0] = loadBitMap("../sprites/jr/ide0.png");

    junior->jumpingLeft[0] = loadBitMap("../sprites/jr/jl0.png");

    junior->jumpingRight[0] = loadBitMap("../sprites/jr/jr0.png");

    junior->ropeLeft[0] = loadBitMap("../sprites/jr/rl0.png");
    junior->ropeLeft[1] = loadBitMap("../sprites/jr/rl1.png");

    junior->ropeRight[0] = loadBitMap("../sprites/jr/rr0.png");
    junior->ropeRight[1] = loadBitMap("../sprites/jr/rr1.png");

    junior->rope[0] = loadBitMap("../sprites/jr/rr0.png");
}
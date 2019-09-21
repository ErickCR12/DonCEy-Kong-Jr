//
// Created by Erick Barrantes on 9/19/2019.
//

#include "CollisionHandler.h"

int isCollidingWithPlatform(Junior *junior, Platform **platforms){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    for(int i = 0; i < PLATFORMS_TOTAL; i++) {
        float xPlatform = platforms[i]->entity->x;
        float yPlatform = platforms[i]->entity->y;
        if ((xJr - platforms[i]->width) <= xPlatform && (xJr + JR_WIDTH) >= xPlatform &&
            (yJr + JR_HEIGHT) >= yPlatform && (yJr + JR_HEIGHT) <= (yPlatform + (PLATFORM_HEIGHT/8)))
            return TRUE;
    }return FALSE;
}

int isCollidingWithRope(Junior *junior, Rope **ropes){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    for(int i = 0; i < AMOUNT_OF_ROPES; i++) {
        float xRope = ropes[i]->entity->x;
        float yRope = ropes[i]->entity->y;
        if ((xJr + JR_WIDTH) >= (xRope) && xJr <= (xRope + ROPE_WIDTH) &&
            (yJr > yRope) && yJr < (yRope + ROPE_HEIGHT))
            return TRUE;
    }return FALSE;
}
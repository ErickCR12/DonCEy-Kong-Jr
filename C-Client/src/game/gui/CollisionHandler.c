//
// Created by Erick Barrantes on 9/19/2019.
//

#include "CollisionHandler.h"

int isCollidingWithPlatform(Junior *junior, Platform **platform){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    for(int i = 0; i < PLATFORMS_TOTAL; i++) {
        float xPlatform = platform[i]->entity->x;
        float yPlatform = platform[i]->entity->y;
        if ((xJr - platform[i]->width) <= xPlatform && (xJr + JR_WIDTH) >= xPlatform &&
            (yJr + JR_HEIGHT) >= yPlatform && (yJr + JR_HEIGHT) <= (yPlatform + (PLATFORM_HEIGHT/8)))
            return TRUE;
    }return FALSE;
}
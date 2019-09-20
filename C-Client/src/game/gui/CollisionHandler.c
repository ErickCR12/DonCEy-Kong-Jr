//
// Created by Erick Barrantes on 9/19/2019.
//

#include "CollisionHandler.h"

int isCollidingWithPlatform(Junior *junior, Platform **platform){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    for(int i = 0; i < AMOUNT_OF_PLATFORMS; i++) {
        float xPlatform = platform[i]->entity->x;
        float yPlatform = platform[i]->entity->y;
        if (xJr <= (xPlatform + platform[i]->width) && xJr >= (xPlatform - JR_WIDTH) && yJr >= (yPlatform - 15)
            && yJr <= yPlatform)
            return TRUE;
    }return FALSE;
}
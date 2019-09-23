//
// Created by Erick Barrantes on 9/22/2019.
//

#include "Croco.h"
#include "../gui/CollisionHandler.h"
#include "../gui/GameWindow.h"

void moveCroco(Croco *croco){
    if(!croco->isRedCroco){
        if(croco->entity->x < croco->rope->entity->x)
            croco->entity->x += CROCO_SPEED;
        else
            croco->entity->y += CROCO_SPEED;
        if(!isCollidingWithPlatform(croco->entity, platforms))
            croco->entity->y += CROCO_SPEED;
    }
}
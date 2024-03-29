//
// Created by Erick Barrantes on 9/19/2019.
//

#include "CollisionHandler.h"
#include <stdio.h>

int isCollidingWithPlatform(Entity *entity, Platform **platforms){
    float xEntity = entity->x;
    float yEntity = entity->y;
    float entityWidth = entity->width;
    float entityHeight = entity->height;
    for(int i = 0; i < PLATFORMS_TOTAL; i++) {
        float xPlatform = platforms[i]->entity->x;
        float yPlatform = platforms[i]->entity->y;
        if ((xEntity - platforms[i]->width) <= xPlatform && (xEntity + entityWidth - 15) >= xPlatform &&
            (yEntity + entityHeight) >= yPlatform && (yEntity + entityHeight) <= (yPlatform + (PLATFORM_HEIGHT / 8)))
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
            (yJr > yRope) && yJr < (yRope + ROPE_HEIGHT + 5))
            return TRUE;
    }return FALSE;
}

int isCollindingWithKey(Junior *junior, Entity *key){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    float xKey = key->x;
    float yKey = key->y;
    if(xJr < (xKey + KEY_WIDTH) && (xJr + JR_WIDTH) > xKey && yKey > yJr && yKey < (yJr + JR_HEIGHT))
        return TRUE;
    return FALSE;
}

int isCollidingWithCroco(Junior *junior, LinkedList *crocos){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    for(Node *crocoNode = crocos->head; crocoNode != NULL; crocoNode = crocoNode->nextNode){
        float xCroco = ((Croco*)crocoNode->data)->entity->x;
        float yCroco = ((Croco*)crocoNode->data)->entity->y;
        if ((xJr + JR_WIDTH) > xCroco && xJr < (xCroco + CROCO_WIDTH) &&
            (yCroco + CROCO_HEIGHT) > yJr && yCroco < (yJr + JR_HEIGHT))
            return TRUE;
    }return FALSE;
}

void isCollidingWithFruit(Junior *junior, LinkedList *fruits){
    float xJr = junior->entity->x;
    float yJr = junior->entity->y;
    for(Node *fruitNode = fruits->head; fruitNode != NULL; fruitNode = fruitNode->nextNode){
        float xFruit = ((Fruit*)fruitNode->data)->entity->x;
        float yFruit = ((Fruit*)fruitNode->data)->entity->y;
        if ((xJr + JR_WIDTH) > xFruit && xJr < (xFruit + CROCO_WIDTH) &&
            (yFruit + FRUIT_HEIGHT) > yJr && yFruit < (yJr + JR_HEIGHT))
            deleteNode(fruits, fruitNode);
    }
}
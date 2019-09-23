//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_COLLISIONHANDLER_H
#define C_CLIENT_COLLISIONHANDLER_H

#include "../entities/Junior.h"
#include "../../util/var.h"
#include "../entities/Rope.h"
#include "../entities/Fruit.h"

int isCollidingWithPlatform(Entity *entity, Platform **platforms);
int isCollidingWithRope(Junior *junior, Rope **ropes);
int isCollindingWithKey(Junior *junior, Entity *key);
int isCollidingWithCroco(Junior *junior, LinkedList *crocos);
void isCollidingWithFruit(Junior *junior, LinkedList *fruits);

#endif //C_CLIENT_COLLISIONHANDLER_H

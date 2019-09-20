//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_COLLISIONHANDLER_H
#define C_CLIENT_COLLISIONHANDLER_H

#include "../entities/Junior.h"
#include "../../util/var.h"
#include "../entities/Rope.h"

int isCollidingWithPlatform(Junior *junior, Platform **platforms);
int isCollidingWithRope(Junior *junior, Rope **ropes);

#endif //C_CLIENT_COLLISIONHANDLER_H

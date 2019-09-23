//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_FRUIT_H
#define C_CLIENT_FRUIT_H

#include "Entity.h"
#include "Rope.h"

typedef struct {
    Entity *entity;
    Rope *rope;
} Fruit;

#endif //C_CLIENT_FRUIT_H

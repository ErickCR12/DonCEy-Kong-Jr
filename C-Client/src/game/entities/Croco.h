//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_CROCO_H
#define C_CLIENT_CROCO_H

#include "../../util/var.h"
#include "Entity.h"
#include "Rope.h"

typedef struct {
    Entity *entity;
    int isRedCroco;
    Rope *rope;
} Croco;

void moveCroco(Croco *croco);

#endif //C_CLIENT_CROCO_H

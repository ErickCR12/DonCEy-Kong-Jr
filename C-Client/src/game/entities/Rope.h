//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_ROPE_H
#define C_CLIENT_ROPE_H

#include "../../util/var.h"
#include "Entity.h"

typedef struct {
    Entity *entity;
    float width;
    float height;
} Rope;

Rope* initializeRope(int id, float x, float y, float rx, float ry, char *type, ALLEGRO_BITMAP *bitmap,
                             float width, float height);

#endif //C_CLIENT_ROPE_H

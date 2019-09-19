//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_ENTITY_H
#define C_CLIENT_ENTITY_H

#include <stdlib.h>
#include "../../util/var.h"
#include <allegro5/allegro.h>

typedef struct {
    int id;
    float x;
    float y;
    ALLEGRO_BITMAP *bitmap;
} Entity;

void drawBitmap(Entity *entity);

int collide(Entity);

void kill();

#endif //C_CLIENT_ENTITY_H

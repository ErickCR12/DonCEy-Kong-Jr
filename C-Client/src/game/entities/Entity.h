//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_ENTITY_H
#define C_CLIENT_ENTITY_H

#include <stdlib.h>
#include "../../util/var.h"

typedef struct {
    int id;
    int x;
    int y;
} Entity;

int collide(Entity entity);

void kill();

#endif //C_CLIENT_ENTITY_H

//
// Created by Jesica on 9/20/2019.
//

#ifndef C_CLIENT_ENTITIES_H
#define C_CLIENT_ENTITIES_H

#include "Entity.h"

#define MAX_ENTITIES 30

Entity *entities[MAX_ENTITIES];
int length;

void pushEntity(Entity *);

void removeEntity(int );

json_value *serializeEntities();

#endif //C_CLIENT_ENTITIES_H

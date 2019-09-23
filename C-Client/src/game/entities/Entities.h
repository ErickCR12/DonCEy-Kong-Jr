//
// Created by Jesica on 9/20/2019.
//

#ifndef C_CLIENT_ENTITIES_H
#define C_CLIENT_ENTITIES_H

#include "Entity.h"
#include "Junior.h"

/*
 * Junior, Donkey, platforms, key, ropes
 */
json_value *serializeEntities(Junior *, Entity *, Platform **, Entity *, Rope **);

json_value *serializePlatforms(Platform **);

json_value *serializeRopes(Rope **);

#endif //C_CLIENT_ENTITIES_H

//
// Created by Jesica on 9/20/2019.
//

#ifndef C_CLIENT_ENTITIES_H
#define C_CLIENT_ENTITIES_H

#include "Entity.h"
#include "Junior.h"
#include "Fruit.h"
#include "../../json/json.h"

LinkedList *crocosList;
LinkedList *fruitsList;

/*
 * Function serialized the game entities
 */
json_value *serializeEntities(Junior *, Entity *, Platform **, Entity *, Rope **);

json_value *serializePlatforms(Platform **);

json_value *serializeRopes(Rope **);

json_value *serializeCrocos(LinkedList *crocos);

json_value *serializeFruits(LinkedList *fruits);

#endif //C_CLIENT_ENTITIES_H

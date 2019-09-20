//
// Created by Jesica on 9/20/2019.
//
#include "Entities.h"

void pushEntity(Entity *entity) {
    entity->id = length;
    entities[length] = entity;
    length += 1;
}

void removeEntity(int id) {

}

char *serializeEntities() {
    json_value *obj = json_object_new((size_t) length);

    for (int i = 0; i < length; i++) {
        updateRPoss(entities[i]);
        json_char *jsonEntity = serialize(entities[i]);
        json_value *entity = json_string_new(jsonEntity);
        char *name = entities[i]->type;
        json_object_push(obj, name, entity);
    }

    json_char *buf = malloc(json_measure(obj));
    json_serialize(buf, obj);
    return buf;
}
//
// Created by José Acuña on 18/09/2019.
//

#include <stdio.h>
#include "Entity.h"
#include "../../json/json.h"

Entity* initializeEntity(int id, float x, float y, float rx, float ry, char *type, ALLEGRO_BITMAP *bitmap){
    Entity *entity = (Entity*) malloc(sizeof(Entity));
    entity->id = id;
    entity->x = x;
    entity->y = y;
    entity->rx = rx;
    entity->ry = ry;
    entity->type = type;
    entity->bitmap = bitmap;
    drawBitmap(entity);
    return entity;
}

void drawBitmap(Entity *entity){
    al_draw_bitmap(entity->bitmap, entity->x, entity->y, 0);
}

int collide(Entity entity) {
    return FALSE;
}

void kill() {

}

void updateRPoss(Entity *entity) {
    entity->rx = entity->x / GW_WIDTH;
    entity->ry = entity->y / GW_HEIGHT;
}

ALLEGRO_BITMAP* loadBitMap(char* imgPath) {
    ALLEGRO_BITMAP *bitmap = NULL;
    bitmap = al_load_bitmap(imgPath);
    assert(bitmap != NULL);
    return bitmap;
}

json_value *serialize(Entity *entity) {
    json_value *id = json_integer_new(entity->id);
    json_value *x = json_double_new(entity->rx);
    json_value *y = json_double_new(entity->ry);
    json_value *type = json_string_new(entity->type);
    json_value *width = json_double_new(entity->width);
    json_value *height = json_double_new(entity->height);

    json_value *obj = json_object_new(3);
    json_object_push(obj, "id", id);
    json_object_push(obj, "x", x);
    json_object_push(obj, "y", y);
    json_object_push(obj, "type", type);
    json_object_push(obj, "width", width);
    json_object_push(obj, "height", height);

    //json_char *buf = malloc(json_measure(obj));
    //json_serialize(buf, obj);

    return obj;
}

void parse(char *json, Entity *entity) {
    json_value *obj = json_parse(json, strlen(json));

    entity->id = (int) obj->u.object.values[0].value->u.integer;
    entity->rx = (float) obj->u.object.values[1].value->u.dbl;
    entity->ry = (float) obj->u.object.values[2].value->u.dbl;
    entity->type = obj->u.object.values[3].value->u.string.ptr;
}
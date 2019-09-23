//
// Created by Erick Barrantes on 9/21/2019.
//


#include "Rope.h"

Rope* initializeRope(int id, float x, float y, float rx, float ry, char *type, ALLEGRO_BITMAP *bitmap,
                         float width, float height){
    Rope* rope = (Rope*) malloc(sizeof(Rope));
    rope->entity = initializeEntity(id, x , y, rx, ry, type, bitmap);
    rope->width = width;
    rope->height = height;
    return rope;
}
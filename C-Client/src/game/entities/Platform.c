//
// Created by Erick Barrantes on 9/21/2019.
//


#include "Platform.h"

Platform* initializePlatform(int id, float x, float y, float rx, float ry, char *type, ALLEGRO_BITMAP *bitmap,
                             float width, float height){
    Platform* platform = (Platform*) malloc(sizeof(Platform));
    platform->entity = initializeEntity(id, x , y, rx, ry, type, bitmap);
    platform->width = width;
    platform->height = height;
    return platform;
}
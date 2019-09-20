//
// Created by José Acuña on 18/09/2019.
//

#include "Entity.h"

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
//
// Created by José Acuña on 18/09/2019.
//

#include "Entity.h"

void drawBitmap(Entity *entity){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(entity->bitmap, entity->x, GW_HEIGHT-JR_HEIGHT, 0);
    al_flip_display();
}

int collide(Entity entity) {
    return FALSE;
}

void kill() {

}
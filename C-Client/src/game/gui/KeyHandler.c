//
// Created by Erick Barrantes on 9/19/2019.
//

#include "KeyHandler.h"

void RightKeyPressed(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_BITMAP *jrBitmap, float *x){
    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT )) {
        drawBitmap(jrBitmap, *x + MOV_SPEED);
        *x += MOV_SPEED;
        free(x);
    }
}

void LeftKeyPressed(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_BITMAP *jrBitmap, float *x){
    if (al_key_down(&keyState, ALLEGRO_KEY_LEFT )) {
        drawBitmap(jrBitmap, *x - MOV_SPEED);
        *x -= MOV_SPEED;
        free(x);
    }
}

void drawBitmap(ALLEGRO_BITMAP *jrBitmap, float x){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(jrBitmap, x, GW_HEIGHT-JR_HEIGHT, 0);
    al_flip_display();
}

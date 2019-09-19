//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_KEYHANDLER_H
#define C_CLIENT_KEYHANDLER_H

#include <allegro5/allegro.h>
#include "../../util/var.h"

void RightKeyPressed(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_BITMAP *jrBitmap, float *x);
void LeftKeyPressed(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_BITMAP *jrBitmap, float *x);
void drawBitmap(ALLEGRO_BITMAP *jrBitmap, float x);

#endif //C_CLIENT_KEYHANDLER_H

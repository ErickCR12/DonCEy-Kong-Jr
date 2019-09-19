//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_GAMEWINDOW_H
#define C_CLIENT_GAMEWINDOW_H

#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>
#include "../../util/var.h"

void createGameWindow();
ALLEGRO_EVENT_QUEUE* setEventQueue(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_TIMER *timer);
ALLEGRO_BITMAP* setBitmap();
void gameLoop(ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_BITMAP *jrBitmap);
int eventManager(ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_BITMAP *jrBitmap, float x);
void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_BITMAP *jrBitmap);

#endif //C_CLIENT_GAMEWINDOW_H
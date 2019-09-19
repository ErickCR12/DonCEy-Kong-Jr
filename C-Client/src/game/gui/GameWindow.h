//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_GAMEWINDOW_H
#define C_CLIENT_GAMEWINDOW_H

#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>
#include "../../util/var.h"
#include "../entities/Junior.h"

void createGameWindow();
ALLEGRO_EVENT_QUEUE* setEventQueue(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_TIMER *timer);
Junior createJunior();
ALLEGRO_BITMAP* setBitmap(char* imgPath);
void gameLoop(ALLEGRO_EVENT_QUEUE *eventQueue, Junior *junior);
int eventManager(ALLEGRO_EVENT_QUEUE *eventQueue, Junior *junior);
void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_EVENT_QUEUE *eventQueue, Junior *junior);

#endif //C_CLIENT_GAMEWINDOW_H

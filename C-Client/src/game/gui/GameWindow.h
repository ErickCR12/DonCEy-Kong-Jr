//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_GAMEWINDOW_H
#define C_CLIENT_GAMEWINDOW_H

#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>
#include "../../util/var.h"
#include "../entities/Junior.h"
#include "../entities/Platform.h"


Junior *junior;
Platform *platform;

void createGameWindow();
ALLEGRO_EVENT_QUEUE* setEventQueue(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_TIMER *timer);
void createJunior();
void createPlatform(float x, float y);
ALLEGRO_BITMAP* setBitmap(char* imgPath);
void gameLoop(ALLEGRO_EVENT_QUEUE *eventQueue);
int eventManager(ALLEGRO_EVENT_QUEUE *eventQueue);
void redrawDisplay();
void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_EVENT_QUEUE *eventQueue);

#endif //C_CLIENT_GAMEWINDOW_H

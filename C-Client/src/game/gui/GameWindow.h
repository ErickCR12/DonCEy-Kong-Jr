//
// Created by Erick Barrantes on 9/19/2019.
//

#ifndef C_CLIENT_GAMEWINDOW_H
#define C_CLIENT_GAMEWINDOW_H

#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "../../util/var.h"
#include "../entities/Entities.h"
#include "../entities/Junior.h"
#include "../entities/Platform.h"
#include "../../client/Client.h"
#include "../entities/Rope.h"
#include "../../datastructures/LinkedList.h"
#include "CollisionHandler.h"
#include "../../json/json.h"
#include "../../json/cJSON.h"
#include "../entities/Fruit.h"

Junior *junior;
Entity *donkey;
Platform **platforms;
Rope **ropes;
LinkedList *fruits;
LinkedList *crocos;
Entity *key;
int id;
ALLEGRO_EVENT_QUEUE *eventQueue;

//Creates an ALLEGRO main window where the game is going to be displayed
void createGameWindow();
//Recursive function that calls the game loop. If the player won, it calls startGame recursively. If the player losses,
//it calls closeGameWindow and the app closes.
void startGame(ALLEGRO_DISPLAY *gameWindowDisplay);
//Calls all the functions that creates all the initial widgets in their initial positions. This includes Jr, DK,
//platforms, ropes and the key.
void initializeWidgets(ALLEGRO_DISPLAY *gameWindowDisplay);
ALLEGRO_EVENT_QUEUE* setEventQueue(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_TIMER *timer);
//Initialize Junior Widget.
void createJunior();
void createPlatforms();
void createRopes();
void createCroco(int ropeNumber, int isRedCroco, int id);
void createFruit(int ropeNumber, int id);
int getRopePosition(int ropeColumn);
ALLEGRO_BITMAP* setBitmap(char* imgPath);
int gameLoop();
int eventManager();
void redrawDisplay();
void deleteWidgets();
void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay);
void clientUpdate();
char *serializeGame();
void parseGame(json_char *json);
#endif //C_CLIENT_GAMEWINDOW_H

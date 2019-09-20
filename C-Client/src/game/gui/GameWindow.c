//
// Created by Erick Barrantes on 9/19/2019.
//
#include "GameWindow.h"


void createGameWindow(){
    ALLEGRO_DISPLAY *gameWindowDisplay;
    al_init();
    gameWindowDisplay = al_create_display(GW_WIDTH, GW_HEIGHT);

    ALLEGRO_TIMER *timer = NULL;
    timer = al_create_timer(1.0 / FPS);
    al_start_timer(timer);

    ALLEGRO_EVENT_QUEUE *eventQueue = setEventQueue(gameWindowDisplay, timer);

    createJunior();
    createPlatforms();

    gameLoop(eventQueue);

    closeGameWindow(gameWindowDisplay, eventQueue);
}

ALLEGRO_EVENT_QUEUE* setEventQueue(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_TIMER *timer){
    ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
    eventQueue = al_create_event_queue();
    al_install_keyboard();
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(gameWindowDisplay));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    return eventQueue;
}

void createJunior(){
    junior = (Junior*) malloc(sizeof(Junior));
    junior->entity = (Entity*) malloc(sizeof(Entity));
    junior->entity->x = 120;
    junior->entity->y = 20;
    junior->entity->bitmap = setBitmap("../sprites/jr.png");
    drawBitmap(junior->entity);
}

void createPlatforms(){
    float x = 100;
    float y = 100;
    platforms = (Platform**) malloc(sizeof(Platform*));
    for(int i = 0; i < AMOUNT_OF_PLATFORMS; i++) {
        platforms[i] = (Platform*) malloc(sizeof(Platform));
        platforms[i]->entity = (Entity *) malloc(sizeof(Entity));
        platforms[i]->entity->x = x;
        platforms[i]->entity->y = y;
        platforms[i]->entity->bitmap = setBitmap("../sprites/platform.png");
        platforms[i]->width = 100;
        platforms[i]->height = 20;
        drawBitmap(platforms[i]->entity);
        x += 100;
        y += 100;
    }
}

ALLEGRO_BITMAP* setBitmap(char* imgPath){
    ALLEGRO_BITMAP *bitmap = NULL;
    al_init_image_addon();
    bitmap = al_load_bitmap(imgPath);
    assert(bitmap != NULL);
    return bitmap;
}

void gameLoop(ALLEGRO_EVENT_QUEUE *eventQueue){
    int running = TRUE;
    ALLEGRO_KEYBOARD_STATE keyState;
    while (running) {
        running = eventManager(eventQueue);

        al_get_keyboard_state(&keyState);

        moveJrRight(junior, keyState);
        moveJrLeft(junior, keyState);
        moveJrDown(junior, platforms);
    }
}

int eventManager(ALLEGRO_EVENT_QUEUE *eventQueue){
    ALLEGRO_EVENT event;
    if (!al_is_event_queue_empty(eventQueue)) {
        al_wait_for_event(eventQueue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            return FALSE;
        if(event.type == ALLEGRO_EVENT_TIMER) {
            redrawDisplay();
        }
    }
    return TRUE;
}

void redrawDisplay(){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for(int i = 0; i < AMOUNT_OF_PLATFORMS; i++)
        drawBitmap(platforms[i]->entity);
    drawBitmap(junior->entity);
    al_flip_display();
}
void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_EVENT_QUEUE *eventQueue){
    al_destroy_display(gameWindowDisplay);
    al_uninstall_keyboard();
    al_destroy_bitmap(junior->entity->bitmap);
    al_destroy_event_queue(eventQueue);
    free(junior);
    for(int i = 0; i < AMOUNT_OF_PLATFORMS; i++)
        free(platforms[i]);
    free(platforms);
}
//
// Created by Erick Barrantes on 9/19/2019.
//
#include "GameWindow.h"
#include "KeyHandler.h"

void createGameWindow(){
    ALLEGRO_DISPLAY *gameWindowDisplay;
    al_init();
    gameWindowDisplay = al_create_display(GW_WIDTH, GW_HEIGHT);

    ALLEGRO_TIMER *timer = NULL;
    timer = al_create_timer(1.0 / FPS);


    ALLEGRO_EVENT_QUEUE *eventQueue = setEventQueue(gameWindowDisplay, timer);

    ALLEGRO_BITMAP *jrBitmap = setBitmap();

    al_start_timer(timer);
    gameLoop(eventQueue, jrBitmap);

    closeGameWindow(gameWindowDisplay, eventQueue, jrBitmap);
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

ALLEGRO_BITMAP* setBitmap(){
    ALLEGRO_BITMAP *jrBitmap = NULL;
    al_init_image_addon();
    jrBitmap = al_load_bitmap("../sprites/jr.png");
    assert(jrBitmap != NULL);
    drawBitmap(jrBitmap, 0);
    return jrBitmap;
}

void gameLoop(ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_BITMAP *jrBitmap){
    int running = TRUE;
    float x = 0;
    ALLEGRO_KEYBOARD_STATE keyState;
    while (running) {
        running = eventManager(eventQueue, jrBitmap, x);

        al_get_keyboard_state(&keyState);

        RightKeyPressed(keyState, jrBitmap, &x);
        LeftKeyPressed(keyState, jrBitmap, &x);
    }
}

int eventManager(ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_BITMAP *jrBitmap, float x){
    ALLEGRO_EVENT event;
    if (!al_is_event_queue_empty(eventQueue)) {
        al_wait_for_event(eventQueue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            return FALSE;
        if(event.type == ALLEGRO_EVENT_TIMER)
            drawBitmap(jrBitmap, x);
    }
    return TRUE;
}

void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_BITMAP *jrBitmap){
    al_destroy_display(gameWindowDisplay);
    al_uninstall_keyboard();
    al_destroy_bitmap(jrBitmap);
    al_destroy_event_queue(eventQueue);
}
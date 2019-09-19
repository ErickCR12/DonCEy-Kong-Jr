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

    Junior junior = createJunior();

    gameLoop(eventQueue, &junior);

    closeGameWindow(gameWindowDisplay, eventQueue, &junior);
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

Junior createJunior(){
    Junior junior;
    junior.entity = (Entity*) malloc(sizeof(Entity));
    junior.entity->x = 0;
    junior.entity->y = GW_HEIGHT - JR_HEIGHT;
    junior.entity->bitmap = setBitmap("../sprites/jr.png");
    drawBitmap(junior.entity);
    return junior;
}

ALLEGRO_BITMAP* setBitmap(char* imgPath){
    ALLEGRO_BITMAP *bitmap = NULL;
    al_init_image_addon();
    bitmap = al_load_bitmap(imgPath);
    assert(bitmap != NULL);
    return bitmap;
}

void gameLoop(ALLEGRO_EVENT_QUEUE *eventQueue, Junior *junior){
    int running = TRUE;
    ALLEGRO_KEYBOARD_STATE keyState;
    while (running) {
        running = eventManager(eventQueue, junior);

        al_get_keyboard_state(&keyState);

        moveJrRight(junior, keyState);
        moveJrLeft(junior, keyState);
    }
}

int eventManager(ALLEGRO_EVENT_QUEUE *eventQueue, Junior *junior){
    ALLEGRO_EVENT event;
    if (!al_is_event_queue_empty(eventQueue)) {
        al_wait_for_event(eventQueue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            return FALSE;
        if(event.type == ALLEGRO_EVENT_TIMER)
            drawBitmap(junior->entity);
    }
    return TRUE;
}

void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay, ALLEGRO_EVENT_QUEUE *eventQueue, Junior* junior){
    al_destroy_display(gameWindowDisplay);
    al_uninstall_keyboard();
    al_destroy_bitmap(junior->entity->bitmap);
    al_destroy_event_queue(eventQueue);
    free(junior);
}
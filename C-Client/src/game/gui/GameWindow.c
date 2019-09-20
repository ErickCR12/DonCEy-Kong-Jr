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
    junior->entity->y = 50;
    junior->entity->type = "junior";
    junior->entity->bitmap = setBitmap("../sprites/jr.png");
    drawBitmap(junior->entity);

    pushEntity(junior->entity);
}

void createPlatforms(){
    //float width[] = {100, 50, 30, 200, 150};
    platforms = (Platform**) malloc(sizeof(Platform*));
    for(int i = 0; i < AMOUNT_OF_PLATFORMS; i++) {
        platforms[i] = (Platform*) malloc(sizeof(Platform));
        platforms[i]->entity = (Entity *) malloc(sizeof(Entity));
        platforms[i]->entity->x = PLATFORM_X_POS[i];
        platforms[i]->entity->y = PLATFORM_Y_POS[i];
        platforms[i]->entity->type = "platform";
        platforms[i]->entity->bitmap = setBitmap("../sprites/platform.png");
        platforms[i]->width = PLATFORM_WIDTH;
        platforms[i]->height = PLATFORM_HEIGHT;
        drawBitmap(platforms[i]->entity);

        //pushEntity(platforms[i]->entity);
//        al_draw_scaled_bitmap(platforms[i]->entity->bitmap, x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT,
//                                                            x, y, platforms[i]->width, platforms[i]->height, 0);
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
    int playing = TRUE;
    float jumpCount = 0.0f;
    int jumping = FALSE;
    int timer = 0;
    int falling = FALSE;
    ALLEGRO_KEYBOARD_STATE keyState;
    while (playing) {
        playing = eventManager(eventQueue);

        al_get_keyboard_state(&keyState);

        moveJrRight(junior, keyState);
        moveJrLeft(junior, keyState);
        if(!jumping) falling = moveJrDown(junior, platforms);
        if(!falling) jumping = moveJrUp(junior, keyState, &jumpCount, jumping, platforms);

//        timer++;
//        if (timer > 30000) {
//            clientUpdate();
//            timer = 0;
//        }
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
    for(int i = 0; i < AMOUNT_OF_PLATFORMS; i++) {
        drawBitmap(platforms[i]->entity);
//        al_draw_scaled_bitmap(platforms[i]->entity->bitmap, platforms[i]->entity->x, platforms[i]->entity->y,
//                PLATFORM_WIDTH, PLATFORM_HEIGHT, platforms[i]->entity->x, platforms[i]->entity->y, platforms[i]->width,
//                platforms[i]->height, 0);
    }
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
    //free(platforms);
}

void clientUpdate() {
    json_value *jsonEntities = serializeEntities();
    message(serializeGame(jsonEntities));
}

char *serializeGame(json_value *entities) {
    json_value *obj = json_object_new((size_t) length);

    json_value *game = json_integer_new(id);

    json_object_push(obj, "game", game);
    json_object_push(obj, "entities", entities);

    json_char *buf = malloc(json_measure(obj));
    json_serialize(buf, obj);
    return buf;
}
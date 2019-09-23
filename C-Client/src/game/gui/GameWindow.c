//
// Created by Erick Barrantes on 9/19/2019.
//
#include "GameWindow.h"


void createGameWindow(){
    ALLEGRO_DISPLAY *gameWindowDisplay;
    al_init();
    gameWindowDisplay = al_create_display(GW_WIDTH, GW_HEIGHT);

    startGame(gameWindowDisplay);
}

void startGame(ALLEGRO_DISPLAY *gameWindowDisplay){
    initializeWidgets(gameWindowDisplay);
    int win = gameLoop(eventQueue);
    deleteWidgets();
    if(win)
        startGame(gameWindowDisplay);
    else
        closeGameWindow(gameWindowDisplay);
}

void initializeWidgets(ALLEGRO_DISPLAY *gameWindowDisplay){
    al_init_image_addon();

    ALLEGRO_TIMER *timer = NULL;
    timer = al_create_timer(1.0 / FPS);
    al_start_timer(timer);

    eventQueue = setEventQueue(gameWindowDisplay, timer);

    createJunior();
    createPlatforms();
    createRopes();
    crocos = initializeList();
    fruits = initializeList();

    crocosList = crocos;
    fruitsList = fruits;

    donkey = initializeEntity(0, DK_X_POS, DK_Y_POS, DK_X_POS, DK_Y_POS, "donkey", setBitmap("../sprites/dk.png"));
    key = initializeEntity(0, KEY_X_POS, KEY_Y_POS, KEY_X_POS, KEY_Y_POS, "key", setBitmap("../sprites/key.png"));

    donkey->width = DONKEY_WIDTH;
    donkey->height = DONKEY_HEIGHT;
    key->width = KEY_WIDTH;
    key->height = KEY_HEIGHT;
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
    junior->entity = initializeEntity(1, JR_X_INITIAL, JR_Y_INITIAL, JR_X_INITIAL, JR_Y_INITIAL, "junior",
                                      setBitmap("../sprites/jr.png"));
    junior->entity->width = JR_WIDTH;
    junior->entity->height = JR_HEIGHT;
    loadBitMaps(junior);
}

void createPlatforms(){
    platforms = (Platform**) malloc(PLATFORMS_TOTAL * sizeof(Platform*));
    char* imgPath = NULL;
    float x, y;
    for(int i = 0; i < PLATFORMS_TOTAL; i++) {
        if(i < AMOUNT_PLATFORMS1){
            x = PLATFORM1_X_POS[i];
            y = PLATFORM1_Y_POS[i];
            imgPath = "../sprites/platform1.png";
        }else{
            x = PLATFORM2_X_POS[i - AMOUNT_PLATFORMS1];
            y = PLATFORM2_Y_POS[i - AMOUNT_PLATFORMS1];
            imgPath = "../sprites/platform2.png";
        }
        platforms[i] = initializePlatform(i+2, x, y, x, y, "platform", setBitmap(imgPath), PLATFORM_WIDTH,
                                           PLATFORM_HEIGHT);
        platforms[i]->entity->width = PLATFORM_WIDTH;
        platforms[i]->entity->height = PLATFORM_HEIGHT;
    }
}

void createRopes(){
    ropes = (Rope**) malloc(AMOUNT_OF_ROPES * sizeof(Rope*));
    char* imgPath = "../sprites/rope.png";
    for(int i = 0; i < AMOUNT_OF_ROPES; i++) {
        ropes[i] = initializeRope(0, ROPE_X_POSITION[i], ROPE_Y_POSITION[i], ROPE_X_POSITION[i], ROPE_Y_POSITION[i],
                                  "rope", setBitmap(imgPath), ROPE_WIDTH, ROPE_HEIGHT);
        ropes[i]->entity->width = ROPE_WIDTH;
        ropes[i]->entity->height = ROPE_HEIGHT;
    }
    free(imgPath);
}

void createCroco(int ropeNumber, int isRedCroco, int Id){
    Croco *croco = (Croco*) malloc(sizeof(Croco));
    char *imgPath;
    if(isRedCroco)
        imgPath = "../sprites/redcroco.png";
    else
        imgPath = "../sprites/bluecroco.png";
    croco->entity = initializeEntity(1, CROCO_X_POS, CROCO_Y_POS, CROCO_X_POS, CROCO_Y_POS, "croco",
                                      setBitmap(imgPath));
    croco->entity->width = CROCO_WIDTH;
    croco->entity->height = CROCO_HEIGHT;
    croco->entity->id = Id;
    croco->isRedCroco = isRedCroco;
    croco->rope = ropes[getRopePosition(ropeNumber)];
    Node *node = initializeNode(croco);
    insertNode(crocos, node);
}

void createFruit(int ropeNumber, int id){
    Fruit *fruit = (Fruit*) malloc(sizeof(Fruit));
    char *imgPath = "../sprites/fruit.png";
    fruit->rope = ropes[getRopePosition(ropeNumber + 1) - 1];


    fruit->entity = initializeEntity(1, fruit->rope->entity->x, fruit->rope->entity->y + 10,
                                     fruit->rope->entity->x, fruit->rope->entity->y + 10, "fruit",
                                     setBitmap(imgPath));
    fruit->entity->width = FRUIT_WIDTH;
    fruit->entity->height = FRUIT_HEIGHT;
    fruit->entity->id = id;
    Node *node = initializeNode(fruit);
    insertNode(fruits, node);
}

int getRopePosition(int ropeColumn){
    if(ropeColumn >= ROPE_COLUMNS) return AMOUNT_OF_ROPES;
    float prevX = -1.0f;
    int ropeNumber = -1;
    for(int i = 0; i < AMOUNT_OF_ROPES; i++){
        if(prevX != ropes[i]->entity->x){
            prevX = ropes[i]->entity->x;
            ropeNumber++;
        }
        if(ropeNumber == ropeColumn)
            return i;
    }
    return  -1;
}

ALLEGRO_BITMAP* setBitmap(char* imgPath){
    ALLEGRO_BITMAP *bitmap = NULL;
    bitmap = al_load_bitmap(imgPath);
    assert(bitmap != NULL);
    return bitmap;
}

int gameLoop(){
    int playing = TRUE, falling = FALSE, jumping = FALSE, win = FALSE;
    float jumpCount = 0.0f;
    int timer = 0;
    ALLEGRO_KEYBOARD_STATE keyState;
    while (playing) {
        playing = eventManager(eventQueue);

        al_get_keyboard_state(&keyState);

        notMov(junior, keyState);
        moveJrRight(junior, keyState);
        moveJrLeft(junior, keyState);
        isCollidingWithFruit(junior, fruits);
        if(!jumping) falling = moveJrDown(junior, keyState, platforms, ropes);
        if(!falling) jumping = moveJrUp(junior, keyState, &jumpCount, jumping, platforms, ropes);
        for(Node *crocoNode = crocos->head; crocoNode != NULL; crocoNode = crocoNode->nextNode) {
            if(((Croco*)crocoNode->data)->entity->y < GW_HEIGHT)
                moveCroco(crocoNode->data);
            else
                deleteNode(crocos, crocoNode);
        }
        animate(junior);
        timer++;

        if(isCollindingWithKey(junior, key)){
            win = TRUE;
            playing = FALSE;
        }

        if(isCollidingWithCroco(junior, crocos) || junior->entity->y > GW_HEIGHT)
            playing = FALSE;

        if (timer > 200000) {
            clientUpdate();
            timer = 0;
        }
    }return win;
}

int eventManager(){
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
    for(int i = 0; i < PLATFORMS_TOTAL; i++)
        drawBitmap(platforms[i]->entity);
    for(int i = 0; i < AMOUNT_OF_ROPES; i++)
        drawBitmap(ropes[i]->entity);
    for(Node *node = crocos->head; node != NULL; node = node->nextNode)
        drawBitmap(((Croco*)node->data)->entity);
    for(Node *node = fruits->head; node != NULL; node = node->nextNode)
        drawBitmap(((Fruit*)node->data)->entity);
    drawBitmap(junior->entity);
    drawBitmap(donkey);
    drawBitmap(key);
    al_flip_display();
}

void deleteWidgets(){
    al_destroy_bitmap(junior->entity->bitmap);
    al_destroy_bitmap(donkey->bitmap);
    al_destroy_bitmap(key->bitmap);
    for(int i = 0; i < PLATFORMS_TOTAL; i++)
        free(platforms[i]);
    for(int i = 0; i < AMOUNT_OF_ROPES; i++)
        free(ropes[i]);
    free(junior);
    free(donkey);
    free(key);
    free(platforms);
    free(ropes);
}

void closeGameWindow(ALLEGRO_DISPLAY *gameWindowDisplay){
    al_destroy_display(gameWindowDisplay);
    al_uninstall_keyboard();
    al_destroy_event_queue(eventQueue);
}

void clientUpdate() {
    updateRPoss(junior->entity);
    updateRPoss(donkey);
    updateRPoss(key);

    char *response = message(serializeGame());
    parseGame(response);
}

char *serializeGame() {
    json_value *obj = json_object_new((size_t) 2);

    json_value *game = json_integer_new(id);
    json_value *jsonEntities = serializeEntities(junior, donkey, platforms, key, ropes);

    json_object_push(obj, "game", game);
    json_object_push(obj, "entities", jsonEntities);

    json_char *buf = malloc(json_measure(obj));
    json_serialize(buf, obj);
    return buf;
}


void parseGame(json_char *json) {
    cJSON *jsonObj = cJSON_Parse(json);
    if (jsonObj == NULL) return;

    cJSON *croco;
    cJSON *jsonCrocos = cJSON_DetachItemFromObject(jsonObj, "crocos");
    cJSON_ArrayForEach(croco, jsonCrocos) {
        int rope = cJSON_GetObjectItem(croco, "rope")->valueint;
        int id = cJSON_GetObjectItem(croco, "id")->valueint;
        createCroco(rope, 0, id);
    }

    cJSON *fruit;
    cJSON *jsonFruits = cJSON_DetachItemFromObject(jsonObj, "fruits");
    cJSON_ArrayForEach(fruit, jsonFruits) {
        int rope = cJSON_GetObjectItem(fruit, "rope")->valueint;
        int id = cJSON_GetObjectItem(fruit, "id")->valueint;
        createFruit(rope, id);
    }
}
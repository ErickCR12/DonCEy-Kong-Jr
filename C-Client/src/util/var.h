//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_VAR_H
#define C_CLIENT_VAR_H

#define TRUE 1
#define FALSE 0

#define GW_WIDTH 1200
#define GW_HEIGHT 600
#define PLATFORM_WIDTH 50.0f
#define PLATFORM_HEIGHT 25.0f
#define JR_WIDTH 100.0f
#define JR_HEIGHT 57.0f
#define DONKEY_WIDTH 190.0f
#define DONKEY_HEIGHT 122.0f
#define ROPE_WIDTH 35.0f
#define ROPE_HEIGHT 50.0f
#define KEY_WIDTH 43.0f
#define KEY_HEIGHT 50.0f
#define CROCO_WIDTH 40.0f
#define CROCO_HEIGHT 21.0f

#define JR_X_INITIAL 15
#define JR_Y_INITIAL 420
#define JR_ANIM_TIME 100000

#define DK_X_POS 40
#define DK_Y_POS 0

#define KEY_X_POS 260
#define KEY_Y_POS 70

#define CROCO_X_POS 0
#define CROCO_Y_POS 100
#define CROCO_SPEED 0.00020f

#define FPS 60
#define MOV_SPEED 0.00040f
#define GRAV_SPEED 0.00060f
#define CLIMBING_DOWN_SPEED 0.00060f
#define CLIMBING_UP_SPEED 0.00020f
#define JUMP_HEIGHT 90

#define AMOUNT_PLATFORMS1 10
#define AMOUNT_PLATFORMS2 28

static int PLATFORMS_TOTAL = AMOUNT_PLATFORMS1 + AMOUNT_PLATFORMS2;

static float PLATFORM1_X_POS[] = {15, 65, 200, 330, 460, 510, 660, 890, 1040, 1090};

static float PLATFORM1_Y_POS[] = {500, 500, 460, 550, 510, 510, 470, 510, 450, 450};

static float PLATFORM2_X_POS[] = {0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500,
                                 525, 575, 625, 675, 725, 775, 825, 875, 925, 975,
                                 120, 170,
                                 385,
                                 700,
                                 1025, 1075,
                                 1050};

static float PLATFORM2_Y_POS[] = {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
                                 144, 144, 144, 144, 144, 144, 144, 144, 144, 144,
                                 290, 290,
                                 400,
                                 280,
                                 320, 320,
                                 50};

#define AMOUNT_OF_ROPES 32

static float ROPE_X_POSITION[] = {40, 40, 40, 40, 40,
                                  150,
                                  275, 275, 275, 275, 275, 275, 275,
                                  395, 395, 395, 395,
                                  525, 525, 525, 525,
                                  710,
                                  800, 800, 800,
                                  895, 895, 895, 895,
                                  1060, 1060, 1060};

static float ROPE_Y_POSITION[] = {145, 195, 245, 295, 345,
                                  145,
                                  145, 195, 245, 295, 345, 395, 445,
                                  145, 195, 245, 295,
                                  169, 219, 269, 319,
                                  169,
                                  169, 219, 269,
                                  169, 219, 269, 319,
                                  75, 125, 175};

#endif //C_CLIENT_VAR_H

//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_VAR_H
#define C_CLIENT_VAR_H

#define TRUE 1
#define FALSE 0

#define GW_WIDTH 1200
#define GW_HEIGHT 600
#define PLATFORM_WIDTH 50
#define PLATFORM_HEIGHT 25
#define JR_WIDTH 65.0f
#define JR_HEIGHT 57.0f
#define ROPE_WIDTH 35
#define ROPE_HEIGHT 50

#define JR_X_INITIAL 90
#define JR_Y_INITIAL 210

#define DK_X_POS 40
#define DK_Y_POS 0

#define FPS 60
#define MOV_SPEED 0.00040f
#define CLIMBING_SPEED 0.00020f
#define JUMP_HEIGHT 70

#define AMOUNT_PLATFORMS1 11
#define AMOUNT_PLATFORMS2 16

static int PLATFORMS_TOTAL = AMOUNT_PLATFORMS1 + AMOUNT_PLATFORMS2;

static float PLATFORM1_X_POS[] = {15, 65, 200, 330, 460, 510, 660, 800, 940, 1070, 1120};

static float PLATFORM1_Y_POS[] = {500, 500, 460, 550, 510, 510, 470, 420, 380, 320, 320};

static float PLATFORM2_X_POS[] = {0, 50, 100, 150, 200, 250, 300, 350,
                                 400, 450, 500, 550, 600,
                                 120, 170, 385};

static float PLATFORM2_Y_POS[] = {120, 120, 120, 120, 120, 120, 120, 120,
                                 145, 145, 145, 145, 145,
                                 290, 290, 400};

#define AMOUNT_OF_ROPES 2

static float ROPE_X_POSITION[] = {40, 40};
static float ROPE_Y_POSITION[] = {145, 195};

#endif //C_CLIENT_VAR_H

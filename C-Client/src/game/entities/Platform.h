//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_PLATFORM_H
#define C_CLIENT_PLATFORM_H

#include "../../util/var.h"
#include "Entity.h"
typedef struct {
    Entity *entity;
    int width;
    int height;
} Platform
;

#endif //C_CLIENT_PLATFORM_H

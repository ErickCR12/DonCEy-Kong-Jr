//
// Created by Erick Barrantes on 9/21/2019.
//

#ifndef C_CLIENT_NODE_H
#define C_CLIENT_NODE_H

#include "../game/entities/Croco.h"

typedef struct Node Node;

struct Node{
  Node *nextNode;
  Croco *croco;
};

Node *initializeNode(Croco *croco);

#endif //C_CLIENT_NODE_H

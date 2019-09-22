//
// Created by Erick Barrantes on 9/21/2019.
//

#include "Node.h"

Node* initializeNode(Croco *croco){
    Node *node = (Node*) malloc(sizeof(Node));
    node->nextNode = NULL;
    node->croco = croco;
    return node;
}
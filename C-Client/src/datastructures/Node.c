//
// Created by Erick Barrantes on 9/21/2019.
//

#include "Node.h"

Node* initializeNode(void *data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->nextNode = NULL;
    node->data = data;
    return node;
}
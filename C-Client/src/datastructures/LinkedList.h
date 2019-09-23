//
// Created by Erick Barrantes on 9/21/2019.
//

#ifndef C_CLIENT_LINKEDLIST_H
#define C_CLIENT_LINKEDLIST_H

#include "Node.h"

typedef struct{
    Node *head;
    int amountOfNodes;
}LinkedList;

LinkedList *initializeList();
void insertNode(LinkedList *list, Node *node);
void deleteNode(LinkedList *list, Node *node);
int size(LinkedList *list);

#endif //C_CLIENT_LINKEDLIST_H

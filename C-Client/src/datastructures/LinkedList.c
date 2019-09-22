//
// Created by Erick Barrantes on 9/21/2019.
//

#include "LinkedList.h"

LinkedList *initializeList(){
    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->amountOfCrocos = 0;
    return list;
}


void insertNode(LinkedList *list, Node* node){
    if(list->head == NULL)
        list->head = node;
    else{
        Node* lastNode = list->head;
        while(lastNode->nextNode != NULL)
            lastNode = lastNode->nextNode;
        lastNode->nextNode = node;
    }list->amountOfCrocos++;
}

void deleteNode(LinkedList *list, Node* node){

}

int size(LinkedList *list) {
    Node *tmp = list->head;
    int size = 0;
    while (tmp != NULL) {
        tmp = tmp->nextNode;
        size++;
    }
    return size;
}

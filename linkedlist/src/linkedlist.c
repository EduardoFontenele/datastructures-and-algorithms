#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value;
    struct node* next;
} node;

struct linkedlist {
    node* head;
    node* tail;
};

linkedlist* list_create(void) {
    linkedlist* list = malloc(sizeof(linkedlist));
    if(list == NULL) 
        return NULL;
    
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_destroy(linkedlist* list) {
    free(list);
}

void list_insert(linkedlist* list, int data) {
    node* new_node = malloc(sizeof(node));
    
    if(new_node == NULL) return;
    
    new_node->value = data;
    new_node->next = NULL;
    

    if(list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

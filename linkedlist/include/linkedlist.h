#pragma once

typedef struct linkedlist linkedlist;

linkedlist* list_create(void);
void list_destroy(linkedlist* list);
void list_insert(linkedlist* list, int data);
void list_remove(linkedlist* list, int data);
int list_find(linkedlist* list, int data);
void list_print(linkedlist* list);
int list_size(linkedlist* list);
int list_is_empty(linkedlist* list);
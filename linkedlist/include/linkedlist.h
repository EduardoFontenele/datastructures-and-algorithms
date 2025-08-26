#pragma once

typedef struct linkedlist linkedlist;

linkedlist* list_create(void);
void list_destroy(linkedlist*);
void list_prepend(linkedlist*, int);
void list_append(linkedlist*, int);
void list_remove_head(linkedlist*);
void list_remove_tail(linkedlist*);
void list_remove(linkedlist*, int);
int* list_find(linkedlist*, int);
void list_print(linkedlist*);
int list_size(linkedlist*);
int list_is_empty(linkedlist*);
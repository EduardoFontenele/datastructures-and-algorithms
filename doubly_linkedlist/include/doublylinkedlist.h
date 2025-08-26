#pragma once
#include <stdbool.h>

typedef struct doubly_linked_list doubly_linked_list;

doubly_linked_list* dlist_create(void);
void dlist_destroy(doubly_linked_list*);
void dlist_push_front(doubly_linked_list*, void*);
void dlist_push_back(doubly_linked_list*, void*);
void dlist_insert(doubly_linked_list*, int, void*);
void* dlist_pop_front(doubly_linked_list*);
void* dlist_pop_back(doubly_linked_list*);
void* dlist_remove(doubly_linked_list*, int);
void* dlist_get(doubly_linked_list*, int);
void* dlist_front(doubly_linked_list*);
void* dlist_back(doubly_linked_list*);
int dlist_size(doubly_linked_list*);
bool dlist_empty(doubly_linked_list*);
void dlist_clear(doubly_linked_list*);
void dlist_print(doubly_linked_list*, void(*)(void*));
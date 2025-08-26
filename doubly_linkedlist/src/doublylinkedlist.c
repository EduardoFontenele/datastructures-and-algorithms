#include "doublylinkedlist.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

typedef struct node {
    struct node* next;
    struct node* prev;
    void* data;
} node_t;

struct doubly_linked_list {
    node_t* head;
    node_t* tail;
    uint64_t size;
};

typedef struct {
    doubly_linked_list* dlist;
    uint64_t limit;
} dlist_info_t;

static void* cleaner_func(void* arg) {
    dlist_info_t* dlist_info = (dlist_info_t*) arg;
}

doubly_linked_list* dlist_create() {
    doubly_linked_list* dlist = malloc(sizeof(doubly_linked_list));

    if(!dlist) return NULL;

    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->size = 0UL;
}

void dlist_destroy(doubly_linked_list* dlist) {
    if(dlist == NULL || dlist->head == NULL) return;

    node_t* current = dlist->head;

    while(current != NULL) {        
        node_t* next_node = current->next;
        free(current->data);
        free(current);
        current = next_node;
    }
}

void dlist_print(doubly_linked_list* dlist, void(*print_func)(void*)) {
    if(dlist == NULL || dlist->head == NULL) return;

    pthread_t threads[2];

    if(dlist->size % 2UL != 0UL) {
        uint64_t first_half = (dlist->size + 1UL) / 2UL;
        uint64_t second_half = dlist->size - first_half;

        for(int i = 0; i < 2; i++) {
            pthread_create(&threads[i], NULL, cleaner_func, dlist);
        }

        for(int i = 0; i < 2; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    node_t* current = dlist->head;

    while(current != NULL) {
        print_func(current->data);
        current = current->next;
    }
}
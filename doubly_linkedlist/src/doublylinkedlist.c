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
   node_t* start_node;
   uint64_t count;
   void(*print_func)(void*);
} dlist_info_t;

static node_t* create_node(void* data) {
    node_t* node = malloc(sizeof(node_t));
    if(node == NULL) exit(1);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

static node_t* get_node_at_position(doubly_linked_list* dlist, int position) {
    if(dlist == NULL || dlist->head == NULL || position < 0) return NULL;
    
    int i = 0;
    node_t* current = dlist->head;

    while(i < position && current != NULL) {
        current = current->next;
        i++;
    }

    return current;
}

static void free_all_nodes(node_t* head) {
    node_t* current = head;
    while(current != NULL) {        
        node_t* next_node = current->next;
        free(current);
        current = next_node;
    }
}

static void* print_handler(void* arg) {
   dlist_info_t* info = (dlist_info_t*) arg;
   node_t* current = info->start_node;
   
   for(uint64_t i = 0UL; i < info->count && current != NULL; i++) {
       info->print_func(current->data);
       current = current->next;
   }
   
   return NULL;
}

doubly_linked_list* dlist_create() {
    doubly_linked_list* dlist = malloc(sizeof(doubly_linked_list));

    if(!dlist) return NULL;

    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->size = 0UL;
    return dlist;
}

void dlist_destroy(doubly_linked_list* dlist) {
    if(dlist == NULL) return;

    free_all_nodes(dlist->head);
    free(dlist);
}

void dlist_push_front(doubly_linked_list* dlist, void* data) {
    if(dlist == NULL) return;

    node_t* new_head = create_node(data);
    
    if(dlist->head == NULL) {
        dlist->head = new_head;
        dlist->tail = new_head;
    } else {
        new_head->next = dlist->head;
        dlist->head->prev = new_head;
        dlist->head = new_head;
    }

    dlist->size++;
}

void dlist_push_back(doubly_linked_list* dlist, void* data) {
    if(dlist == NULL) return;

    node_t* new_tail = create_node(data);
    
    if(dlist->head == NULL) {
        dlist->head = new_tail;
        dlist->tail = new_tail;
    } else {
        dlist->tail->next = new_tail;
        new_tail->prev = dlist->tail;
        dlist->tail = new_tail;
    }

    dlist->size++;
}

void dlist_insert(doubly_linked_list* dlist, int position, void* data) {
    if(dlist == NULL) return;
    
    if(position <= 0) {
        dlist_push_front(dlist, data);
        return;
    }
    
    if(dlist->head == NULL || position >= dlist->size) {
        dlist_push_back(dlist, data);
        return;
    }
    
    node_t* new_node = create_node(data);
    node_t* current = get_node_at_position(dlist, position);

    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
    dlist->size++;
}

void* dlist_pop_front(doubly_linked_list* dlist) {
    if(dlist == NULL || dlist->head == NULL) return NULL;

    void* content = dlist->head->data;
    node_t* prev_head = dlist->head;
    
    if(dlist->head->next == NULL) {
        dlist->head = NULL;
        dlist->tail = NULL;
    } else {
        dlist->head = dlist->head->next;
        dlist->head->prev = NULL;
    }
    
    free(prev_head);
    dlist->size--;

    return content;
}

void* dlist_pop_back(doubly_linked_list* dlist) {
    if(dlist == NULL || dlist->head == NULL) return NULL;

    void* content = dlist->tail->data;
    node_t* prev_tail = dlist->tail;
    
    if(dlist->tail->prev == NULL) {
        dlist->head = NULL;
        dlist->tail = NULL;
    } else {
        dlist->tail = dlist->tail->prev;
        dlist->tail->next = NULL;
    }

    free(prev_tail);
    dlist->size--;

    return content;
}

void* dlist_remove(doubly_linked_list* dlist, int position) {
    if(dlist == NULL || dlist->size == 0L) return NULL;

    if(position <= 0) return dlist_pop_front(dlist);
    if(position >= dlist->size - 1) return dlist_pop_back(dlist);

    node_t* current = get_node_at_position(dlist, position);
    if(current == NULL) return NULL;

    void* content = current->data;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
    dlist->size--;
    return content;
}

void* dlist_get(doubly_linked_list* dlist, int position) {
    node_t* current = get_node_at_position(dlist, position);
    return current ? current->data : NULL;
}

void* dlist_front(doubly_linked_list* dlist) {
    if(dlist == NULL || dlist->head == NULL) return NULL;
    return dlist->head->data;
}

void* dlist_back(doubly_linked_list* dlist) {
    if(dlist == NULL || dlist->tail == NULL) return NULL;
    return dlist->tail->data;
}

int dlist_size(doubly_linked_list* dlist) {
    if(dlist == NULL) return 0;
    return (int)dlist->size;
}

bool dlist_empty(doubly_linked_list* dlist) {
    if(dlist == NULL) return true;
    return dlist->size == 0;
}

void dlist_clear(doubly_linked_list* dlist) {
    if(dlist == NULL) return;

    free_all_nodes(dlist->head);

    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->size = 0;
}

void dlist_print(doubly_linked_list* dlist, void(*print_func)(void*)) {
   if(dlist == NULL || dlist->head == NULL) return;

   if(dlist->size == 1UL) {
       print_func(dlist->head->data);
       return;
   }

   pthread_t threads[2];
   dlist_info_t thread_data[2];
   
   uint64_t first_half = (dlist->size + 1UL) / 2UL;
   uint64_t second_half = dlist->size - first_half;
   
   thread_data[0] = (dlist_info_t){
       .dlist = dlist,
       .start_node = dlist->head,
       .count = first_half,
       .print_func = print_func
   };
   
   node_t* middle = dlist->head;
   for(uint64_t i = 0UL; i < first_half; i++) {
       middle = middle->next;
   }
   
   thread_data[1] = (dlist_info_t){
       .dlist = dlist,
       .start_node = middle,
       .count = second_half,
       .print_func = print_func
   };
   
   for(int i = 0; i < 2; i++) {
       pthread_create(&threads[i], NULL, print_handler, &thread_data[i]);
   }
   
   for(int i = 0; i < 2; i++) {
       pthread_join(threads[i], NULL);
   }
}
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node;

struct linkedlist {
    node* head;
    node* tail;
    size_t size;
};


static node* create_node(int value) {
    node* new_node = malloc(sizeof(node));
    if (!new_node) return NULL;
    
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

static void insert_first_node(linkedlist* list, node* new_node) {
    list->head = new_node;
    list->tail = new_node;
    list->size = 1;
}

static int is_single_element(linkedlist* list) {
    return list->head == list->tail;
}

static node* find_node_before_tail(linkedlist* list) {
    node* current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }
    return current;
}


linkedlist* list_create(void) {
    linkedlist* list = malloc(sizeof(linkedlist));
    if (!list) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_destroy(linkedlist* list) {
    if (!list) return;
    
    node* current = list->head;
    while (current) {
        node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void list_prepend(linkedlist* list, int data) {
    if (!list) return;
    
    node* new_node = create_node(data);
    if (!new_node) return;

    if (!list->head) {
        insert_first_node(list, new_node);
        return;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void list_append(linkedlist* list, int data) {
    if (!list) return;
    
    node* new_node = create_node(data);
    if (!new_node) return;

    if (!list->head) {
        insert_first_node(list, new_node);
        return;
    }

    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
}

void list_remove_head(linkedlist* list) {
    if (!list || !list->head) return;

    node* old_head = list->head;
    list->head = list->head->next;
    
    if (!list->head) {
        list->tail = NULL;
    }
    
    free(old_head);
    list->size--;
}

void list_remove_tail(linkedlist* list) {
    if (!list || !list->head) return;

    if (is_single_element(list)) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }

    node* new_tail = find_node_before_tail(list);
    free(list->tail);
    new_tail->next = NULL;
    list->tail = new_tail;
    list->size--;
}

void list_remove(linkedlist* list, int data) {
    if (!list || !list->head) return;

    if (list->head->value == data) {
        list_remove_head(list);
        return;
    }

    node* current = list->head;
    while (current->next && current->next->value != data) {
        current = current->next;
    }

    if (!current->next) return;

    node* to_remove = current->next;
    current->next = to_remove->next;
    
    if (to_remove == list->tail) {
        list->tail = current;
    }
    
    free(to_remove);
    list->size--;
}

int* list_find(linkedlist* list, int data) {
    if (!list || !list->head) return NULL;

    node* current = list->head;
    while (current) {
        if (current->value == data) {
            return &current->value;
        }
        current = current->next;
    }
    
    return NULL;
}

void list_print(linkedlist* list) {
    if (!list || !list->head) {
        printf("Lista vazia\n");
        return;
    }
    
    node* current = list->head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int list_size(linkedlist* list) {
    return list ? list->size : 0;
}

int list_is_empty(linkedlist* list) {
    return list ? (list->size == 0) : 1;
}
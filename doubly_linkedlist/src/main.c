#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

void print_int(void* data) {
    printf("%d ", *(int*)data);
}

int main(void) {
    doubly_linked_list* dlist = dlist_create();
    
    printf("Testing dlist_empty: %s\n", dlist_empty(dlist) ? "true" : "false");
    printf("Testing dlist_size: %d\n", dlist_size(dlist));
    
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    
    printf("\nTesting dlist_push_back:\n");
    dlist_push_back(dlist, &a);
    dlist_push_back(dlist, &b);
    dlist_push_back(dlist, &c);
    printf("Size: %d, Empty: %s\n", dlist_size(dlist), dlist_empty(dlist) ? "true" : "false");
    printf("List: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    printf("\nTesting dlist_push_front:\n");
    dlist_push_front(dlist, &d);
    dlist_push_front(dlist, &e);
    printf("List: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    printf("\nTesting dlist_front and dlist_back:\n");
    printf("Front: %d, Back: %d\n", *(int*)dlist_front(dlist), *(int*)dlist_back(dlist));
    
    printf("\nTesting dlist_get:\n");
    for(int i = 0; i < dlist_size(dlist); i++) {
        int* val = (int*)dlist_get(dlist, i);
        printf("Position %d: %d\n", i, val ? *val : -1);
    }
    
    printf("\nTesting dlist_insert at position 2:\n");
    int f = 10;
    dlist_insert(dlist, 2, &f);
    printf("List: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    printf("\nTesting dlist_pop_front:\n");
    int* popped = (int*)dlist_pop_front(dlist);
    printf("Popped: %d\n", popped ? *popped : -1);
    printf("List: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    printf("\nTesting dlist_pop_back:\n");
    popped = (int*)dlist_pop_back(dlist);
    printf("Popped: %d\n", popped ? *popped : -1);
    printf("List: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    printf("\nTesting dlist_remove at position 1:\n");
    int* removed = (int*)dlist_remove(dlist, 1);
    printf("Removed: %d\n", removed ? *removed : -1);
    printf("List: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    printf("\nTesting dlist_clear:\n");
    dlist_clear(dlist);
    printf("Size after clear: %d, Empty: %s\n", dlist_size(dlist), dlist_empty(dlist) ? "true" : "false");
    
    printf("\nTesting edge cases with single element:\n");
    dlist_push_back(dlist, &a);
    printf("List with one element: ");
    dlist_print(dlist, print_int);
    printf("\n");
    
    popped = (int*)dlist_pop_front(dlist);
    printf("Popped single element: %d\n", popped ? *popped : -1);
    printf("Empty after pop: %s\n", dlist_empty(dlist) ? "true" : "false");
    
    dlist_destroy(dlist);
    printf("\nAll tests completed!\n");
    
    return 0;
}
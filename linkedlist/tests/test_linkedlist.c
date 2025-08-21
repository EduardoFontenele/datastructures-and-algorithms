#include "unity/unity.h"
#include "linkedlist.h"

void setUp(void) {
    // Setup antes de cada teste
}

void tearDown(void) {
    // Cleanup depois de cada teste
}

void test_list_create_should_return_valid_pointer(void) {
    linkedlist* list = list_create();
    TEST_ASSERT_NOT_NULL(list);
    list_destroy(list);
}

void test_list_create_multiple_instances(void) {
    linkedlist* list1 = list_create();
    linkedlist* list2 = list_create();
    
    TEST_ASSERT_NOT_NULL(list1);
    TEST_ASSERT_NOT_NULL(list2);
    TEST_ASSERT_NOT_EQUAL(list1, list2);
    
    list_destroy(list1);
    list_destroy(list2);
}
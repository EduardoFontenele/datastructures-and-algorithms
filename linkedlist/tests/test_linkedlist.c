#include "unity/unity.h"
#include "linkedlist.h"


void test_list_create_should_return_valid_pointer(void) {
    linkedlist* list = list_create();
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_TRUE(list_is_empty(list));
    TEST_ASSERT_EQUAL_INT(0, list_size(list));
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

void test_list_prepend_single_element(void) {
    linkedlist* list = list_create();
    
    list_prepend(list, 42);
    
    TEST_ASSERT_FALSE(list_is_empty(list));
    TEST_ASSERT_EQUAL_INT(1, list_size(list));
    
    int* found = list_find(list, 42);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(42, *found);
    
    list_destroy(list);
}

void test_list_append_single_element(void) {
    linkedlist* list = list_create();
    
    list_append(list, 99);
    
    TEST_ASSERT_FALSE(list_is_empty(list));
    TEST_ASSERT_EQUAL_INT(1, list_size(list));
    
    int* found = list_find(list, 99);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(99, *found);
    
    list_destroy(list);
}

void test_list_prepend_multiple_elements(void) {
    linkedlist* list = list_create();
    
    list_prepend(list, 10);
    list_prepend(list, 20);
    list_prepend(list, 30);
    
    TEST_ASSERT_EQUAL_INT(3, list_size(list));
    TEST_ASSERT_NOT_NULL(list_find(list, 10));
    TEST_ASSERT_NOT_NULL(list_find(list, 20));
    TEST_ASSERT_NOT_NULL(list_find(list, 30));
    
    list_destroy(list);
}

void test_list_append_multiple_elements(void) {
    linkedlist* list = list_create();
    
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    
    TEST_ASSERT_EQUAL_INT(3, list_size(list));
    TEST_ASSERT_NOT_NULL(list_find(list, 10));
    TEST_ASSERT_NOT_NULL(list_find(list, 20));
    TEST_ASSERT_NOT_NULL(list_find(list, 30));
    
    list_destroy(list);
}


void test_list_find_existing_element(void) {
    linkedlist* list = list_create();
    
    list_append(list, 123);
    list_append(list, 456);
    
    int* found = list_find(list, 123);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(123, *found);
    
    found = list_find(list, 456);
    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL_INT(456, *found);
    
    list_destroy(list);
}

void test_list_find_nonexisting_element(void) {
    linkedlist* list = list_create();
    
    list_append(list, 123);
    
    int* found = list_find(list, 999);
    TEST_ASSERT_NULL(found);
    
    list_destroy(list);
}

void test_list_find_empty_list(void) {
    linkedlist* list = list_create();
    
    int* found = list_find(list, 42);
    TEST_ASSERT_NULL(found);
    
    list_destroy(list);
}


void test_list_remove_head_single_element(void) {
    linkedlist* list = list_create();
    
    list_append(list, 42);
    TEST_ASSERT_EQUAL_INT(1, list_size(list));
    
    list_remove_head(list);
    TEST_ASSERT_EQUAL_INT(0, list_size(list));
    TEST_ASSERT_TRUE(list_is_empty(list));
    
    list_destroy(list);
}

void test_list_remove_tail_single_element(void) {
    linkedlist* list = list_create();
    
    list_append(list, 42);
    TEST_ASSERT_EQUAL_INT(1, list_size(list));
    
    list_remove_tail(list);
    TEST_ASSERT_EQUAL_INT(0, list_size(list));
    TEST_ASSERT_TRUE(list_is_empty(list));
    
    list_destroy(list);
}

void test_list_remove_by_value(void) {
    linkedlist* list = list_create();
    
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    
    list_remove(list, 20);
    
    TEST_ASSERT_EQUAL_INT(2, list_size(list));
    TEST_ASSERT_NULL(list_find(list, 20));
    TEST_ASSERT_NOT_NULL(list_find(list, 10));
    TEST_ASSERT_NOT_NULL(list_find(list, 30));
    
    list_destroy(list);
}

void test_list_remove_nonexisting_element(void) {
    linkedlist* list = list_create();
    
    list_append(list, 42);
    int original_size = list_size(list);
    
    list_remove(list, 999);
    
    TEST_ASSERT_EQUAL_INT(original_size, list_size(list));
    
    list_destroy(list);
}

void test_operations_on_empty_list(void) {
    linkedlist* list = list_create();
    
    list_remove_head(list);
    list_remove_tail(list);
    list_remove(list, 42);
    
    TEST_ASSERT_TRUE(list_is_empty(list));
    TEST_ASSERT_EQUAL_INT(0, list_size(list));
    
    list_destroy(list);
}
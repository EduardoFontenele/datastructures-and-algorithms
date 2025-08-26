#include "unity/unity.h"

// === DECLARAÇÕES DOS TESTES ===

// Testes de criação
void test_list_create_should_return_valid_pointer(void);
void test_list_create_multiple_instances(void);

// Testes de inserção
void test_list_prepend_single_element(void);
void test_list_append_single_element(void);
void test_list_prepend_multiple_elements(void);
void test_list_append_multiple_elements(void);

// Testes de busca
void test_list_find_existing_element(void);
void test_list_find_nonexisting_element(void);
void test_list_find_empty_list(void);

// Testes de remoção
void test_list_remove_head_single_element(void);
void test_list_remove_tail_single_element(void);
void test_list_remove_by_value(void);
void test_list_remove_nonexisting_element(void);

// Testes de edge cases
void test_operations_on_empty_list(void);

int main(void) {
    UNITY_BEGIN();
    
    printf("\n=== LINKEDLIST TESTS ===\n");
    
    printf("\n--- Creation Tests ---\n");
    RUN_TEST(test_list_create_should_return_valid_pointer);
    RUN_TEST(test_list_create_multiple_instances);
    
    printf("\n--- Insertion Tests ---\n");
    RUN_TEST(test_list_prepend_single_element);
    RUN_TEST(test_list_append_single_element);
    RUN_TEST(test_list_prepend_multiple_elements);
    RUN_TEST(test_list_append_multiple_elements);
    
    printf("\n--- Search Tests ---\n");
    RUN_TEST(test_list_find_existing_element);
    RUN_TEST(test_list_find_nonexisting_element);
    RUN_TEST(test_list_find_empty_list);
    
    printf("\n--- Removal Tests ---\n");
    RUN_TEST(test_list_remove_head_single_element);
    RUN_TEST(test_list_remove_tail_single_element);
    RUN_TEST(test_list_remove_by_value);
    RUN_TEST(test_list_remove_nonexisting_element);
    
    printf("\n--- Edge Case Tests ---\n");
    RUN_TEST(test_operations_on_empty_list);
    
    printf("\n=== TESTS COMPLETE ===\n");
    
    return UNITY_END();
}
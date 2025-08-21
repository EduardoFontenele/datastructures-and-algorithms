#include "unity/unity.h"

// Declarar as funções de teste
void test_list_create_should_return_valid_pointer(void);
void test_list_create_multiple_instances(void);

int main(void) {
    UNITY_BEGIN();
    
    printf("=== LinkedList Create Tests ===\n");
    RUN_TEST(test_list_create_should_return_valid_pointer);
    RUN_TEST(test_list_create_multiple_instances);
    
    return UNITY_END();
}
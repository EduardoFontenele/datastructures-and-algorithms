cmake_minimum_required(VERSION 3.10)
project(LinkedList LANGUAGES C)

add_executable(programa
    src/main.c
    src/linkedlist.c
)

add_executable(tests
    tests/test_runner.c
    tests/test_linkedlist.c
    tests/unity/unity.c
    src/linkedlist.c
)

target_include_directories(programa PRIVATE include)

target_include_directories(tests PRIVATE include tests)
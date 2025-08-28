cmake_minimum_required(VERSION 3.10)
project(DoublyLinkedList LANGUAGES C)

add_executable(main
    src/main.c
    src/doublylinkedlist.c
)

target_include_directories(main PRIVATE include)
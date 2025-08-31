package com.binarysearchtree.structures;

class Node<T> {
    private final T value;
    private Node<T> left;
    private Node<T> right;

    Node(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }
}

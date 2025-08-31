package com.binarysearchtree.structures;

import java.util.Comparator;

import static java.util.Objects.isNull;

public class BinarySearchTree<T> {
    private Node<T> root;
    private boolean isEmpty;
    private long size;
    private final Comparator<T> comparator;

    public BinarySearchTree(Comparator<T> comparator) {
        this.comparator = comparator;
        isEmpty = true;
        size = 0L;
    }

    public void insert(T value) {
        var newNode = new Node<T>(value);

        if(isNull(root)) {
            root = newNode;
        } else {

        }

        isEmpty = false;
        size++;
    }

    public boolean isEmpty() { return isEmpty; }

    public long getSize() { return size; }

    public T getRoot() {
        return isNull(root) ? null : root.getValue();
    }
}

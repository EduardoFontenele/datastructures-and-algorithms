package com.binarysearchtree;

import com.binarysearchtree.structures.BinarySearchTree;

import java.util.Comparator;

public class App {
    public static void main(String[] args) {
        var stringComparator = "Omega".compareTo("Alfa");
        System.out.println(stringComparator);
        var students = new BinarySearchTree<String>(Comparator.naturalOrder());
    }
}

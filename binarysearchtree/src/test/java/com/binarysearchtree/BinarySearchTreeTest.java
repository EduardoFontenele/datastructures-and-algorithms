package com.binarysearchtree;

import com.binarysearchtree.structures.BinarySearchTree;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class BinarySearchTreeTest {

    @Test
    @DisplayName("When create a tree, size should be zero and root should be null")
    void shouldCreateTreeAndEmptyAndSizeEqualsZero() {
        var bst = new BinarySearchTree<>(Integer::compare);

        assertTrue(bst.isEmpty());
        assertNull(bst.getRoot());
        assertEquals(0L, bst.getSize());
    }


    @Test
    @DisplayName("When create a tree, and insert a value, size should be 1 and should not be empty")
    void shouldCreateAndInsertAndSizeBeOneAndShouldNotBeEmpty() {
        var bst = new BinarySearchTree<>(Integer::compare);

        assertTrue(bst.isEmpty());
        assertNull(bst.getRoot());
        assertEquals(0L, bst.getSize());

        bst.insert(10);

        assertFalse(bst.isEmpty());
        assertNotNull(bst.getRoot());
        assertEquals(1L, bst.getSize());
        assertEquals(10, bst.getRoot());
    }
}

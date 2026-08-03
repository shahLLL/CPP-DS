#include <catch2/catch_test_macros.hpp>
#include "../headers/binary_search_tree.h"

TEST_CASE("BINARY SEARCH TREE TEST CASE #1", "[binary_search_tree]") {
    int val1 = 2;
    int val2 = 1;
    int val3 = 3;
    BinarySearchTree<int> bst = BinarySearchTree<int>();
    REQUIRE(bst.isEmpty());
    REQUIRE(bst.getSize() == 0);

    REQUIRE(!bst.contains(val1));
    REQUIRE(!bst.contains(val2));
    REQUIRE(!bst.contains(val3));

    REQUIRE(bst.add(val1));

    REQUIRE(!bst.isEmpty());
    REQUIRE(bst.getSize() == 1);
    REQUIRE(bst.contains(val1));
    REQUIRE(!bst.contains(val2));
    REQUIRE(!bst.contains(val3));

    REQUIRE(bst.add(val2));

    REQUIRE(!bst.isEmpty());
    REQUIRE(bst.getSize() == 2);
    REQUIRE(bst.contains(val1));
    REQUIRE(bst.contains(val2));
    REQUIRE(!bst.contains(val3));

    REQUIRE(bst.add(val3));

    REQUIRE(!bst.isEmpty());
    REQUIRE(bst.getSize() == 3);
    REQUIRE(bst.contains(val1));
    REQUIRE(bst.contains(val2));
    REQUIRE(bst.contains(val3));
}

TEST_CASE("BINARY SEARCH TREE TEST CASE #2", "[binary_search_tree]") {
    double val1 = 2.22;
    double val2 = 1.11;
    double val3 = 3.33;
    BinarySearchTree<double> bst = BinarySearchTree<double>();
    REQUIRE(bst.isEmpty());
    REQUIRE(bst.getSize() == 0);

    REQUIRE(!bst.contains(val1));
    REQUIRE(!bst.contains(val2));
    REQUIRE(!bst.contains(val3));

    REQUIRE(bst.add(val1));

    REQUIRE(!bst.isEmpty());
    REQUIRE(bst.getSize() == 1);
    REQUIRE(bst.contains(val1));
    REQUIRE(!bst.contains(val2));
    REQUIRE(!bst.contains(val3));

    REQUIRE(bst.add(val2));

    REQUIRE(!bst.isEmpty());
    REQUIRE(bst.getSize() == 2);
    REQUIRE(bst.contains(val1));
    REQUIRE(bst.contains(val2));
    REQUIRE(!bst.contains(val3));

    REQUIRE(bst.add(val3));

    REQUIRE(!bst.isEmpty());
    REQUIRE(bst.getSize() == 3);
    REQUIRE(bst.contains(val1));
    REQUIRE(bst.contains(val2));
    REQUIRE(bst.contains(val3));
}

TEST_CASE("BINARY SEARCH TREE TEST CASE #3", "[binary_search_tree]") {
    BinarySearchTree<int> bst = BinarySearchTree<int>();
    for(int i = 0; i < 5; i++) REQUIRE(!bst.remove(i + 1));

    for(int i = 0; i < 5; i++) {
        bst.add(i + 1);
        REQUIRE(bst.getSize() == 1);
        REQUIRE(!bst.isEmpty());
        REQUIRE(bst.remove(i + 1));
        REQUIRE(bst.isEmpty());
        REQUIRE(bst.getSize() == 0);
    }

    for(int i = 0; i < 5; i++) {
        bst.add(i + 1);
        bst.add(i + 2);
        REQUIRE(bst.getSize() == 2);
        REQUIRE(bst.contains(i + 1));
        REQUIRE(bst.contains(i + 2));
        REQUIRE(bst.remove(i + 1));
        REQUIRE(bst.getSize() == 1);
        REQUIRE(!bst.contains(i + 1));
        REQUIRE(bst.contains(i + 2));
        REQUIRE(bst.remove(i + 2));
    }

    for(int i = 0; i < 5; i++) {
        bst.add(i + 2);
        bst.add(i + 1);
        REQUIRE(bst.getSize() == 2);
        REQUIRE(bst.contains(i + 2));
        REQUIRE(bst.contains(i + 1));
        REQUIRE(bst.remove(i + 2));
        REQUIRE(bst.getSize() == 1);
        REQUIRE(!bst.contains(i + 2));
        REQUIRE(bst.contains(i + 1));
        REQUIRE(bst.remove(i + 1));
    }

    for(int i = 0; i < 5; i++) {
        bst.add(i + 2);
        bst.add(i + 1);
        bst.add(i + 3);
        REQUIRE(bst.getSize() == 3);
        REQUIRE(bst.contains(i + 2));
        REQUIRE(bst.contains(i + 1));
        REQUIRE(bst.contains(i + 3));
        REQUIRE(bst.remove(i + 2));
        REQUIRE(bst.getSize() == 2);
        REQUIRE(!bst.contains(i + 2));
        REQUIRE(bst.contains(i + 1));
        REQUIRE(bst.contains(i + 3));
        REQUIRE(bst.remove(i + 1));
        REQUIRE(bst.remove(i + 3));
    }
    
}
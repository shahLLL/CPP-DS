#include <catch2/catch_test_macros.hpp>
#include "../headers/binary_tree_node.h"

TEST_CASE("BINARY TREE NODE TEST CASE #1", "[binary_tree_node]") {
    int val1 = 2;
    int val2 = 1;
    int val3 = 3;

    BinaryTreeNode<int> testNode = BinaryTreeNode<int>(val1);
    REQUIRE(testNode.getVal() == val1);
    REQUIRE(!testNode.hasLeft());
    REQUIRE(!testNode.hasRight());
    REQUIRE(testNode.getLeft() == nullptr);
    REQUIRE(testNode.getRight() == nullptr);

    testNode.setLeft(val2);
    testNode.setRight(val3);
    REQUIRE(testNode.hasLeft());
    REQUIRE(testNode.hasRight());
    REQUIRE(testNode.getLeft()->getVal() == val2);
    REQUIRE(testNode.getRight()->getVal() == val3);
    REQUIRE(!testNode.getLeft()->hasLeft());
    REQUIRE(!testNode.getLeft()->hasRight());
    REQUIRE(!testNode.getRight()->hasLeft());
    REQUIRE(!testNode.getRight()->hasRight());
}

TEST_CASE("BINARY TREE NODE TEST CASE #2", "[binary_tree_node]") {
    double val1 = 2.98;
    double val2 = 1.78;
    double val3 = 3.23;

    BinaryTreeNode<double> testNode = BinaryTreeNode<double>(val1);
    REQUIRE(testNode.getVal() == val1);
    REQUIRE(!testNode.hasLeft());
    REQUIRE(!testNode.hasRight());
    REQUIRE(testNode.getLeft() == nullptr);
    REQUIRE(testNode.getRight() == nullptr);

    testNode.setLeft(val2);
    testNode.setRight(val3);
    REQUIRE(testNode.hasLeft());
    REQUIRE(testNode.hasRight());
    REQUIRE(testNode.getLeft()->getVal() == val2);
    REQUIRE(testNode.getRight()->getVal() == val3);
    REQUIRE(!testNode.getLeft()->hasLeft());
    REQUIRE(!testNode.getLeft()->hasRight());
    REQUIRE(!testNode.getRight()->hasLeft());
    REQUIRE(!testNode.getRight()->hasRight());
}

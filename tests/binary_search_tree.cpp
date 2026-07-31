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
#include <catch2/catch_test_macros.hpp>
#include "../headers/node.h"

TEST_CASE("NODE TEST CASE #1", "[node]") {
    int testInt = 2;
    Node<int> node = Node<int>(testInt);
    REQUIRE(node.getData() == testInt);
    REQUIRE(node.hasNext() == false);
    REQUIRE(node.getNext() == nullptr);
}

TEST_CASE("NODE TEST CASE #2", "[node]") {
    int testInt1 = 4;
    int testInt2 = 2;
    Node<int> node = Node<int>(testInt1);
    REQUIRE(node.getData() == testInt1);
    REQUIRE(node.hasNext() == false);
    REQUIRE(node.getNext() == nullptr);
    node.setNext(testInt2);
    REQUIRE(node.hasNext() == true);
    
    Node<int>* next = node.getNext();
    REQUIRE(next-> getData() == testInt2);
    REQUIRE(next -> hasNext() == false);
    REQUIRE(next -> getNext() == nullptr);
}

TEST_CASE("NODE TEST CASE #3", "[node]") {
    double testDouble1 = 3.0;
    double testDouble2 = 4.5;
    Node<double> node = Node<double>(testDouble1);
    REQUIRE(node.getData() == testDouble1);
    REQUIRE(node.hasNext() == false);
    REQUIRE(node.getNext() == nullptr);
    node.setNext(testDouble2);
    REQUIRE(node.hasNext() == true);

    Node<double>* next = node.getNext();
    REQUIRE(next-> getData() == testDouble2);
    REQUIRE(next -> hasNext() == false);
    REQUIRE(next -> getNext() == nullptr);
}
#include <catch2/catch_test_macros.hpp>
#include "../headers/double_node.h"

TEST_CASE("DOUBLE NODE TEST CASE #1", "[double_node]") {
    int testInt = 1;
    DoubleNode<int> testNode = DoubleNode<int>(testInt);
    REQUIRE(!testNode.hasNext());
    REQUIRE(!testNode.hasPrev());
    REQUIRE(!testNode.getNext());
    REQUIRE(testNode.getPrev().expired());
}

TEST_CASE("DOUBLE NODE TEST CASE #2", "[double_node]") {
    int testInt1 = 3;
    int testInt2 = 5;
    DoubleNode<int> testNode = DoubleNode<int>(testInt1);
    REQUIRE(!testNode.hasNext());
    REQUIRE(!testNode.hasPrev());
    REQUIRE(!testNode.getNext());
    REQUIRE(testNode.getPrev().expired());

    testNode.setNext(testInt2);
    REQUIRE(testNode.hasNext());
    REQUIRE(!testNode.hasPrev());
    REQUIRE(testNode.getNext()->getData() == testInt2);
    REQUIRE(!(testNode.getNext()->hasNext()));
    REQUIRE(!(testNode.getNext()->hasPrev()));
}

TEST_CASE("DOUBLE NODE TEST CASE #3", "[double_node]") {
    int testInt1 = 7;
    int testInt2 = 9;
    DoubleNode<int> testNode = DoubleNode<int>(testInt1);
    std::shared_ptr<DoubleNode<int>> testPrev = std::make_shared<DoubleNode<int>>(testInt2);

    REQUIRE(!testNode.hasNext());
    REQUIRE(!testNode.hasPrev());
    REQUIRE(!testNode.getNext());
    REQUIRE(testNode.getPrev().expired());

    testNode.setPrev(testPrev);
    REQUIRE(!testNode.hasNext());
    REQUIRE(testNode.hasPrev());
    REQUIRE(testNode.getPrev().lock()->getData() == testInt2);
    REQUIRE(!(testNode.getPrev().lock()->hasNext()));
    REQUIRE(!(testNode.getPrev().lock()->hasPrev()));
}

TEST_CASE("DOUBLE NODE TEST CASE #4", "[double_node]") {
    int testInt1 = 4;
    int testInt2 = 6;
    int testInt3 = 8;
    DoubleNode<int> testNode = DoubleNode<int>(testInt1);
    std::shared_ptr<DoubleNode<int>> testPrev = std::make_shared<DoubleNode<int>>(testInt3);

    REQUIRE(!testNode.hasNext());
    REQUIRE(!testNode.hasPrev());
    REQUIRE(!testNode.getNext());
    REQUIRE(testNode.getPrev().expired());

    testNode.setNext(testInt2);
    testNode.setPrev(testPrev);

    REQUIRE(testNode.hasNext());
    REQUIRE(testNode.hasPrev());
    REQUIRE(testNode.getNext()->getData() == testInt2);
    REQUIRE(!testNode.getNext()->hasNext());
    REQUIRE(!testNode.getNext()->hasNext());
    REQUIRE(testNode.getPrev().lock()->getData() == testInt3);
    REQUIRE(!testNode.getPrev().lock()->hasNext());
    REQUIRE(!testNode.getPrev().lock()->hasNext());
}

TEST_CASE("DOUBLE NODE TEST CASE #5", "[double_node]") {
    double testInt1 = 5.5;
    double testInt2 = 7.5;
    double testInt3 = 2.5;
    DoubleNode<double> testNode = DoubleNode<double>(testInt1);
    std::shared_ptr<DoubleNode<double>> testPrev = std::make_shared<DoubleNode<double>>(testInt3);

    REQUIRE(!testNode.hasNext());
    REQUIRE(!testNode.hasPrev());
    REQUIRE(!testNode.getNext());
    REQUIRE(testNode.getPrev().expired());

    testNode.setNext(testInt2);
    testNode.setPrev(testPrev);

    REQUIRE(testNode.hasNext());
    REQUIRE(testNode.hasPrev());
    REQUIRE(testNode.getNext()->getData() == testInt2);
    REQUIRE(!testNode.getNext()->hasNext());
    REQUIRE(!testNode.getNext()->hasNext());
    REQUIRE(testNode.getPrev().lock()->getData() == testInt3);
    REQUIRE(!testNode.getPrev().lock()->hasNext());
    REQUIRE(!testNode.getPrev().lock()->hasNext());
}
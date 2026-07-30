#include <catch2/catch_test_macros.hpp>
#include "../headers/graph_node.h"

TEST_CASE("GRAPH NODE TEST CASE #1", "[graph_node]") {
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    GraphNode<int> graphNode1 = GraphNode<int>(val1);
    GraphNode<int> graphNode2 = GraphNode<int>(val2);
    GraphNode<int> graphNode3 = GraphNode<int>(val3);

    REQUIRE(graphNode1.getVal() == val1);
    REQUIRE(graphNode2.getVal() == val2);
    REQUIRE(graphNode3.getVal() == val3);
    REQUIRE(!graphNode1.isNeighbor(&graphNode2));
    REQUIRE(!graphNode1.isNeighbor(&graphNode3));
    REQUIRE(!graphNode2.isNeighbor(&graphNode1));
    REQUIRE(!graphNode2.isNeighbor(&graphNode3));
    REQUIRE(!graphNode3.isNeighbor(&graphNode1));
    REQUIRE(!graphNode3.isNeighbor(&graphNode2));

    graphNode1.addNeighbor(&graphNode2);
    graphNode1.addNeighbor(&graphNode3);

    REQUIRE(graphNode1.isNeighbor(&graphNode2));
    REQUIRE(graphNode1.isNeighbor(&graphNode3));
    REQUIRE(!graphNode2.isNeighbor(&graphNode1));
    REQUIRE(!graphNode2.isNeighbor(&graphNode3));
    REQUIRE(!graphNode3.isNeighbor(&graphNode1));
    REQUIRE(!graphNode3.isNeighbor(&graphNode2));

    graphNode1.removeNeighbor(&graphNode2);
    REQUIRE(!graphNode1.isNeighbor(&graphNode2));
    REQUIRE(graphNode1.isNeighbor(&graphNode3));
    REQUIRE(!graphNode2.isNeighbor(&graphNode1));
    REQUIRE(!graphNode2.isNeighbor(&graphNode3));
    REQUIRE(!graphNode3.isNeighbor(&graphNode1));
    REQUIRE(!graphNode3.isNeighbor(&graphNode2));

}

TEST_CASE("GRAPH NODE TEST CASE #2", "[graph_node]") {
    double val1 = 1.5;
    double val2 = 2.4;
    double val3 = 3.3;
    GraphNode<double> graphNode1 = GraphNode<double>(val1);
    GraphNode<double> graphNode2 = GraphNode<double>(val2);
    GraphNode<double> graphNode3 = GraphNode<double>(val3);

    REQUIRE(graphNode1.getVal() == val1);
    REQUIRE(graphNode2.getVal() == val2);
    REQUIRE(graphNode3.getVal() == val3);
    REQUIRE(!graphNode1.isNeighbor(&graphNode2));
    REQUIRE(!graphNode1.isNeighbor(&graphNode3));
    REQUIRE(!graphNode2.isNeighbor(&graphNode1));
    REQUIRE(!graphNode2.isNeighbor(&graphNode3));
    REQUIRE(!graphNode3.isNeighbor(&graphNode1));
    REQUIRE(!graphNode3.isNeighbor(&graphNode2));

    graphNode1.addNeighbor(&graphNode2);
    graphNode1.addNeighbor(&graphNode3);

    REQUIRE(graphNode1.isNeighbor(&graphNode2));
    REQUIRE(graphNode1.isNeighbor(&graphNode3));
    REQUIRE(!graphNode2.isNeighbor(&graphNode1));
    REQUIRE(!graphNode2.isNeighbor(&graphNode3));
    REQUIRE(!graphNode3.isNeighbor(&graphNode1));
    REQUIRE(!graphNode3.isNeighbor(&graphNode2));

    graphNode1.removeNeighbor(&graphNode2);
    REQUIRE(!graphNode1.isNeighbor(&graphNode2));
    REQUIRE(graphNode1.isNeighbor(&graphNode3));
    REQUIRE(!graphNode2.isNeighbor(&graphNode1));
    REQUIRE(!graphNode2.isNeighbor(&graphNode3));
    REQUIRE(!graphNode3.isNeighbor(&graphNode1));
    REQUIRE(!graphNode3.isNeighbor(&graphNode2));
}
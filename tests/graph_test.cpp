#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <cstddef>
#include "../headers/graph.h"

TEST_CASE("GRAPH TEST CASES #1", "[graph]" ) {
    Graph<int> graph = Graph<int>();
    REQUIRE(graph.getSize() == 0);
    REQUIRE(graph.isEmpty());

    for(int i = 0; i < 10; i++) {
        REQUIRE(!graph.containsNode(i + 1));
        REQUIRE_THROWS_AS(graph.getNode(i + 1), std::out_of_range);
        REQUIRE_THROWS_WITH(graph.getNode(i + 1), graphGetNodeErrorMessage);

        graph.addNode(i + 1);
        REQUIRE(graph.getSize() == static_cast<std::size_t>(i + 1));
        REQUIRE(!graph.isEmpty());
        REQUIRE(graph.containsNode(i + 1));
        REQUIRE(graph.getNode(i + 1).getVal() == i + 1);
    }

    for(int i = 0; i < 10; i++) {
        REQUIRE(!graph.containsEdge(1, (i + 1)));
        REQUIRE(!graph.containsEdge(2, (i + 1)));
    }

    for(int i = 10; i < 20; i++) {
        REQUIRE_THROWS_AS(graph.containsEdge(1, (i + 1)), std::out_of_range);
        REQUIRE_THROWS_WITH(graph.containsEdge(2, (i + 1)), graphContainsEdgeErrorMessage);
    }

    for(int i = 0; i < 10; i++) {
       graph.addEdge(1, (i + 1));
       graph.addEdge(2, (i + 1));
       REQUIRE(graph.containsEdge(1, (i + 1)));
       REQUIRE(graph.containsEdge(2, (i + 1)));
    }

    REQUIRE_THROWS_AS(graph.addEdge(13, 4), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.addEdge(13, 4), graphAddEdgeErrorMessage);
    REQUIRE_THROWS_AS(graph.addEdge(4, 14), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.addEdge(4, 14), graphAddEdgeErrorMessage);
    REQUIRE_THROWS_AS(graph.addEdge(14, 141), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.addEdge(14, 141), graphAddEdgeErrorMessage);
    
    REQUIRE_THROWS_AS(graph.removeEdge(13, 4), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.removeEdge(13, 4), graphRemoveEdgeErrorMessage);
    REQUIRE_THROWS_AS(graph.removeEdge(4, 14), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.removeEdge(4, 14), graphRemoveEdgeErrorMessage);
    REQUIRE_THROWS_AS(graph.removeEdge(14, 141), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.removeEdge(14, 141), graphRemoveEdgeErrorMessage);

    graph.removeEdge(1, 1);
    graph.removeEdge(1, 2);
    REQUIRE(!graph.containsEdge(1, 1));
    REQUIRE(!graph.containsEdge(1, 2));

    graph.removeNode(8);
    REQUIRE(!graph.containsNode(8));
    REQUIRE_THROWS_AS(graph.getNode(8), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.getNode(8), graphGetNodeErrorMessage);

    REQUIRE_THROWS_AS(graph.containsEdge(1, 8), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.containsEdge(1, 8), graphContainsEdgeErrorMessage);
    REQUIRE_THROWS_AS(graph.containsEdge(2, 8), std::out_of_range);
    REQUIRE_THROWS_WITH(graph.containsEdge(2, 8), graphContainsEdgeErrorMessage);
}
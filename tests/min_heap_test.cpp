#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/min_heap.h"

TEST_CASE("MIN HEAP TESTCASES #1", "[minheap]") {
    MinHeap<int> minHeap = MinHeap<int>();
    int val1 = 9;
    int val2 = 7;
    int val3 = 5;
    REQUIRE(minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 0);
    REQUIRE_THROWS_AS(minHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(minHeap.peek(), minHeapPeekErrorMessage);
    REQUIRE_THROWS_AS(minHeap.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(minHeap.pop(), minHeapPopErrorMessage);

    minHeap.push(val1);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 1);
    REQUIRE(minHeap.peek() == val1);

    minHeap.push(val2);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 2);
    REQUIRE(minHeap.peek() == val2);

    minHeap.push(val3);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 3);
    REQUIRE(minHeap.peek() == val3);

    REQUIRE(minHeap.pop() == val3);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 2);
    REQUIRE(minHeap.peek() == val2);

    REQUIRE(minHeap.pop() == val2);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 1);
    REQUIRE(minHeap.peek() == val1);

    REQUIRE(minHeap.pop() == val1);
    REQUIRE(minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 0);
    REQUIRE_THROWS_AS(minHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(minHeap.peek(), minHeapPeekErrorMessage);
}

TEST_CASE("MIN HEAP TESTCASES #2", "[minheap]") {
    MinHeap<double> minHeap = MinHeap<double>();
    double val1 = 4.82;
    double val2 = 3.21;
    double val3 = 3.20;
    REQUIRE(minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 0);
    REQUIRE_THROWS_AS(minHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(minHeap.peek(), minHeapPeekErrorMessage);
    REQUIRE_THROWS_AS(minHeap.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(minHeap.pop(), minHeapPopErrorMessage);

    minHeap.push(val1);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 1);
    REQUIRE(minHeap.peek() == val1);

    minHeap.push(val2);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 2);
    REQUIRE(minHeap.peek() == val2);

    minHeap.push(val3);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 3);
    REQUIRE(minHeap.peek() == val3);

    REQUIRE(minHeap.pop() == val3);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 2);
    REQUIRE(minHeap.peek() == val2);

    REQUIRE(minHeap.pop() == val2);
    REQUIRE(!minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 1);
    REQUIRE(minHeap.peek() == val1);

    REQUIRE(minHeap.pop() == val1);
    REQUIRE(minHeap.isEmpty());
    REQUIRE(minHeap.getSize() == 0);
    REQUIRE_THROWS_AS(minHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(minHeap.peek(), minHeapPeekErrorMessage);
}
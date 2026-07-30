#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/max_heap.h"

TEST_CASE("MAX HEAP TESTCASES #1", "[maxheap]") {
    MaxHeap<int> maxHeap = MaxHeap<int>();
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    REQUIRE(maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 0);
    REQUIRE_THROWS_AS(maxHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(maxHeap.peek(), maxHeapPeekErrorMessage);
    REQUIRE_THROWS_AS(maxHeap.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(maxHeap.pop(), maxHeapPopErrorMessage);

    maxHeap.push(val1);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 1);
    REQUIRE(maxHeap.peek() == val1);

    maxHeap.push(val2);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 2);
    REQUIRE(maxHeap.peek() == val2);

    maxHeap.push(val3);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 3);
    REQUIRE(maxHeap.peek() == val3);

    REQUIRE(maxHeap.pop() == val3);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 2);
    REQUIRE(maxHeap.peek() == val2);

    REQUIRE(maxHeap.pop() == val2);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 1);
    REQUIRE(maxHeap.peek() == val1);

    REQUIRE(maxHeap.pop() == val1);
    REQUIRE(maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 0);
    REQUIRE_THROWS_AS(maxHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(maxHeap.peek(), maxHeapPeekErrorMessage);
}

TEST_CASE("MAX HEAP TESTCASES #2", "[maxheap]") {
    MaxHeap<double> maxHeap = MaxHeap<double>();
    double val1 = 3.92;
    double val2 = 9.28;
    double val3 = 11.45;
    REQUIRE(maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 0);
    REQUIRE_THROWS_AS(maxHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(maxHeap.peek(), maxHeapPeekErrorMessage);
    REQUIRE_THROWS_AS(maxHeap.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(maxHeap.pop(), maxHeapPopErrorMessage);

    maxHeap.push(val1);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 1);
    REQUIRE(maxHeap.peek() == val1);

    maxHeap.push(val2);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 2);
    REQUIRE(maxHeap.peek() == val2);

    maxHeap.push(val3);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 3);
    REQUIRE(maxHeap.peek() == val3);

    REQUIRE(maxHeap.pop() == val3);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 2);
    REQUIRE(maxHeap.peek() == val2);

    REQUIRE(maxHeap.pop() == val2);
    REQUIRE(!maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 1);
    REQUIRE(maxHeap.peek() == val1);

    REQUIRE(maxHeap.pop() == val1);
    REQUIRE(maxHeap.isEmpty());
    REQUIRE(maxHeap.getSize() == 0);
    REQUIRE_THROWS_AS(maxHeap.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(maxHeap.peek(), maxHeapPeekErrorMessage);
}
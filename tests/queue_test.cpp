#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/queue.h"

TEST_CASE("QUEUE TEST CASE #1", "[queue]") {
    Queue<int> queue = Queue<int>();
    int val1 = 1;
    int val2 = 2;
    REQUIRE(queue.getSize() == 0);
    REQUIRE(queue.isEmpty());
    REQUIRE(!queue.contains(val1));
    REQUIRE(!queue.contains(val2));
    REQUIRE_THROWS_AS(queue.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.peek(), queuePeekEmptyErrorMessage);
    REQUIRE_THROWS_AS(queue.deque(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.deque(), queueDequeEmptyErrorMessage);

    REQUIRE(queue.enque(val1));
    REQUIRE(queue.getSize() == 1);
    REQUIRE(!queue.isEmpty());
    REQUIRE(queue.contains(val1));
    REQUIRE(!queue.contains(val2));
    REQUIRE(queue.peek() == val1);

    REQUIRE(queue.enque(val2));
    REQUIRE(queue.getSize() == 2);
    REQUIRE(!queue.isEmpty());
    REQUIRE(queue.contains(val1));
    REQUIRE(queue.contains(val2));
    REQUIRE(queue.peek() == val1);

    REQUIRE(queue.deque() == val1);
    REQUIRE(queue.getSize() == 1);
    REQUIRE(!queue.isEmpty());
    REQUIRE(!queue.contains(val1));
    REQUIRE(queue.contains(val2));
    REQUIRE(queue.peek() == val2);

    REQUIRE(queue.deque() == val2);
    REQUIRE(queue.getSize() == 0);
    REQUIRE(queue.isEmpty());
    REQUIRE(!queue.contains(val1));
    REQUIRE(!queue.contains(val2));
    REQUIRE_THROWS_AS(queue.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.peek(), queuePeekEmptyErrorMessage);
    REQUIRE_THROWS_AS(queue.deque(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.deque(), queueDequeEmptyErrorMessage);
}

TEST_CASE("QUEUE TEST CASE #2", "[queue]") {
    Queue<double> queue = Queue<double>();
    double val1 = 1.25;
    double val2 = 9.41;
    REQUIRE(queue.getSize() == 0);
    REQUIRE(queue.isEmpty());
    REQUIRE(!queue.contains(val1));
    REQUIRE(!queue.contains(val2));
    REQUIRE_THROWS_AS(queue.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.peek(), queuePeekEmptyErrorMessage);
    REQUIRE_THROWS_AS(queue.deque(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.deque(), queueDequeEmptyErrorMessage);

    REQUIRE(queue.enque(val1));
    REQUIRE(queue.getSize() == 1);
    REQUIRE(!queue.isEmpty());
    REQUIRE(queue.contains(val1));
    REQUIRE(!queue.contains(val2));
    REQUIRE(queue.peek() == val1);

    REQUIRE(queue.enque(val2));
    REQUIRE(queue.getSize() == 2);
    REQUIRE(!queue.isEmpty());
    REQUIRE(queue.contains(val1));
    REQUIRE(queue.contains(val2));
    REQUIRE(queue.peek() == val1);

    REQUIRE(queue.deque() == val1);
    REQUIRE(queue.getSize() == 1);
    REQUIRE(!queue.isEmpty());
    REQUIRE(!queue.contains(val1));
    REQUIRE(queue.contains(val2));
    REQUIRE(queue.peek() == val2);

    REQUIRE(queue.deque() == val2);
    REQUIRE(queue.getSize() == 0);
    REQUIRE(queue.isEmpty());
    REQUIRE(!queue.contains(val1));
    REQUIRE(!queue.contains(val2));
    REQUIRE_THROWS_AS(queue.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.peek(), queuePeekEmptyErrorMessage);
    REQUIRE_THROWS_AS(queue.deque(), std::out_of_range);
    REQUIRE_THROWS_WITH(queue.deque(), queueDequeEmptyErrorMessage);
}
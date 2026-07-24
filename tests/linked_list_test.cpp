#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/linked_list.h"

TEST_CASE("LINKED LIST TEST CASE #1", "[linkedlist]") {
    LinkedList<int> lst = LinkedList<int>();
    REQUIRE(lst.getSize() == 0);
    REQUIRE(lst.isEmpty());
    REQUIRE_THROWS_AS(lst.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(lst.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(lst.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(lst.pop(), popEmptyErrorMessage);

    int val1 = 4;
    REQUIRE(lst.add(val1));
    REQUIRE(lst.getSize() == 1);
    REQUIRE(!lst.isEmpty());
    REQUIRE(lst.peek() == val1);
    REQUIRE(lst.pop() == val1);
    REQUIRE(lst.getSize() == 0);
    REQUIRE(lst.isEmpty());
}

TEST_CASE("LINKED LIST TEST CASE #2", "[linkedlist]") {
    LinkedList<int> lst = LinkedList<int>();
    REQUIRE(lst.getSize() == 0);
    REQUIRE(lst.isEmpty());
    REQUIRE_THROWS_AS(lst.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(lst.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(lst.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(lst.pop(), popEmptyErrorMessage);

    int val1 = 1;
    int val2 = 2;
    REQUIRE(lst.add(val1));
    REQUIRE(lst.add(val2));
    REQUIRE(lst.getSize() == 2);
    REQUIRE(!lst.isEmpty());
    REQUIRE(lst.peek() == val2);
    REQUIRE(lst.pop() == val2);
    REQUIRE(lst.getSize() == 1);
    REQUIRE(!lst.isEmpty());
    REQUIRE(lst.peek() == val1);
    REQUIRE(lst.pop() == val1);
    REQUIRE(lst.getSize() == 0);
    REQUIRE(lst.isEmpty());
}
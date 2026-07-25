#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/stack.h"

TEST_CASE("STACK TEST CASE #1", "[Stack]") {
    Stack<int> stack = Stack<int>();
    int val1 = 4;

    REQUIRE(stack.getSize() == 0);
    REQUIRE(stack.isEmpty());
    REQUIRE(!stack.contains(val1));
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.pop(), popEmptyErrorMessage);
    
    REQUIRE(stack.push(val1));
    REQUIRE(stack.getSize() == 1);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(stack.peek() == val1);
    REQUIRE(stack.pop() == val1);
    REQUIRE(stack.getSize() == 0);
    REQUIRE(stack.isEmpty());
    REQUIRE(!stack.contains(val1));
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.pop(), popEmptyErrorMessage);
}

TEST_CASE("STACK TEST CASE #2", "[Stack]") {
    Stack<int> stack = Stack<int>();
    int val1 = 1;
    int val2 = 2;

    REQUIRE(stack.getSize() == 0);
    REQUIRE(stack.isEmpty());
    REQUIRE(!stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.pop(), popEmptyErrorMessage);

    
    REQUIRE(stack.push(val1));
    REQUIRE(stack.getSize() == 1);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE(stack.peek() == val1);

    REQUIRE(stack.push(val2));
    REQUIRE(stack.getSize() == 2);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(stack.contains(val2));
    REQUIRE(stack.peek() == val2);

    REQUIRE(stack.pop() == val2);
    REQUIRE(stack.getSize() == 1);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE(stack.peek() == val1);

    REQUIRE(stack.pop() == val1);
    REQUIRE(stack.getSize() == 0);
    REQUIRE(stack.isEmpty());
    REQUIRE(!stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.pop(), popEmptyErrorMessage);
}

TEST_CASE("STACK TEST CASE #3", "[Stack]") {
    Stack<double> stack = Stack<double>();
    double val1 = 9.89;
    double val2 = 2.176;

    REQUIRE(stack.getSize() == 0);
    REQUIRE(stack.isEmpty());
    REQUIRE(!stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.pop(), popEmptyErrorMessage);

    
    REQUIRE(stack.push(val1));
    REQUIRE(stack.getSize() == 1);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE(stack.peek() == val1);

    REQUIRE(stack.push(val2));
    REQUIRE(stack.getSize() == 2);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(stack.contains(val2));
    REQUIRE(stack.peek() == val2);

    REQUIRE(stack.pop() == val2);
    REQUIRE(stack.getSize() == 1);
    REQUIRE(!stack.isEmpty());
    REQUIRE(stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE(stack.peek() == val1);

    REQUIRE(stack.pop() == val1);
    REQUIRE(stack.getSize() == 0);
    REQUIRE(stack.isEmpty());
    REQUIRE(!stack.contains(val1));
    REQUIRE(!stack.contains(val2));
    REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.peek(), peekEmptyErrorMessage);
    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
    REQUIRE_THROWS_WITH(stack.pop(), popEmptyErrorMessage);
}
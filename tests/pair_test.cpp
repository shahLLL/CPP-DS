#include <catch2/catch_test_macros.hpp>
#include <string>
#include "../headers/pair.h"

TEST_CASE("PAIR TEST CASE #1", "[pair]") {
    int int1 = 4;
    int int2  = 6;
    Pair<int, int> pair = Pair<int, int>(int1, int2);
    REQUIRE(pair.getKey() == int1);
    REQUIRE(pair.getValue() == int2);
}

TEST_CASE("PAIR TEST CASE #2", "[pair]") {
    int int1 = 2;
    double double1  = 2.22;
    Pair<int, double> pair = Pair<int, double>(int1, double1);
    REQUIRE(pair.getKey() == int1);
    REQUIRE(pair.getValue() == double1);
}

TEST_CASE("PAIR TEST CASE #3", "[pair]") {
    double double1 = 4.0;
    int int1 = 4;
    Pair<double, int> pair = Pair<double, int>(double1, int1);
    REQUIRE(pair.getKey() == double1);
    REQUIRE(pair.getValue() == int1);
}

TEST_CASE("PAIR TEST CASE #4", "[pair]") {
    std::string str1 = "One";
    int int1 = 4;
    Pair<std::string, int> pair = Pair<std::string, int>(str1, int1);
    REQUIRE(pair.getKey() == str1);
    REQUIRE(pair.getValue() == int1);
}
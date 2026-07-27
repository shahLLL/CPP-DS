#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/hash_table.h"

TEST_CASE("HASTABLE TESTCASES #1", "[hastable]") {
    HashTable<int, int> testMap = HashTable<int, int>();
    int key1 = 1;
    int key2 = 2;
    int key3 = 3;
    REQUIRE(testMap.isEmpty());
    REQUIRE(testMap.getSize() == 0);
    REQUIRE(testMap.getCapacity() == hashTableDefaultCapacity);
    REQUIRE(!testMap.contains(key1));
    REQUIRE(!testMap.contains(key2));
    REQUIRE(!testMap.contains(key3));
    REQUIRE(!testMap.remove(key1));
    REQUIRE(!testMap.remove(key2));
    REQUIRE(!testMap.remove(key3));
    REQUIRE_THROWS_AS(testMap.get(key1), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key1), hashTableGetErrorMessage);
    REQUIRE_THROWS_AS(testMap.get(key2), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key2), hashTableGetErrorMessage);
    REQUIRE_THROWS_AS(testMap.get(key3), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key3), hashTableGetErrorMessage);

    REQUIRE(testMap.add(key1, key1 * 2));

    REQUIRE(!testMap.isEmpty());
    REQUIRE(testMap.getSize() == 1);
    REQUIRE(testMap.getCapacity() == hashTableDefaultCapacity);
    REQUIRE(testMap.contains(key1));
    REQUIRE(!testMap.contains(key2));
    REQUIRE(!testMap.contains(key3));
    REQUIRE(testMap.get(key1) == key1 * 2);
    REQUIRE_THROWS_AS(testMap.get(key2), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key2), hashTableGetErrorMessage);
    REQUIRE_THROWS_AS(testMap.get(key3), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key3), hashTableGetErrorMessage);

    REQUIRE(testMap.add(key2, key2 * 2));

    REQUIRE(!testMap.isEmpty());
    REQUIRE(testMap.getSize() == 2);
    REQUIRE(testMap.getCapacity() == hashTableDefaultCapacity);
    REQUIRE(testMap.contains(key1));
    REQUIRE(testMap.contains(key2));
    REQUIRE(!testMap.contains(key3));
    REQUIRE(testMap.get(key1) == key1 * 2);
    REQUIRE(testMap.get(key2) == key2 * 2);
    REQUIRE_THROWS_AS(testMap.get(key3), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key3), hashTableGetErrorMessage);

    REQUIRE(testMap.add(key3, key3 * 2));

    REQUIRE(!testMap.isEmpty());
    REQUIRE(testMap.getSize() == 3);
    REQUIRE(testMap.getCapacity() == hashTableDefaultCapacity);
    REQUIRE(testMap.contains(key1));
    REQUIRE(testMap.contains(key2));
    REQUIRE(testMap.contains(key3));
    REQUIRE(testMap.get(key1) == key1 * 2);
    REQUIRE(testMap.get(key2) == key2 * 2);
    REQUIRE(testMap.get(key3) == key3 * 2);

    REQUIRE(testMap.remove(key2));

    REQUIRE(!testMap.isEmpty());
    REQUIRE(testMap.getSize() == 2);
    REQUIRE(testMap.getCapacity() == hashTableDefaultCapacity);
    REQUIRE(testMap.contains(key1));
    REQUIRE(!testMap.contains(key2));
    REQUIRE(testMap.contains(key3));
    REQUIRE(testMap.get(key1) == key1 * 2);
    REQUIRE(testMap.get(key3) == key3 * 2);
    REQUIRE_THROWS_AS(testMap.get(key2), std::invalid_argument);
    REQUIRE_THROWS_WITH(testMap.get(key2), hashTableGetErrorMessage);
}
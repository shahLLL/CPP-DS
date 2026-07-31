#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "../headers/hash_table.h"

TEST_CASE("HASTABLE TESTCASES #1", "[hash_table]") {
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
    REQUIRE(!testMap.put(key1, 2 * key1));
    REQUIRE(!testMap.put(key2, 2 * key2));
    REQUIRE(!testMap.put(key3, 2 * key3));
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

    REQUIRE(testMap.put(key3, key3 * 4));
    REQUIRE(testMap.get(key3) == key3 * 4);
}

<<<<<<< HEAD
TEST_CASE("HASH TABLE TEST CASE #3", "[hash_table]") {
=======
TEST_CASE("HASH TABLE TEST CASE #2", "[hash_table]") {
>>>>>>> fba2b89 (Implement resizing for hash table)
    HashTable<int, int> hashTable = HashTable<int, int>();
    for(int i = 0; i < 10; i++) {
        hashTable.add(i + 1, i + 11);
        unsigned int expectedCapacity = hashTable.getSize() < 8 ? hashTableDefaultCapacity : hashTableDefaultCapacity * 2;
        REQUIRE(hashTable.getCapacity() == expectedCapacity);
    }

    REQUIRE(!hashTable.isEmpty());
    REQUIRE(hashTable.getSize() == 10);
    for(int i = 0; i < 10; i++) {
        REQUIRE(hashTable.contains(i + 1));
        REQUIRE(hashTable.get(i + 1) == (i + 11));
    }

    for(int i = 0; i < 10; i++) {
        hashTable.remove(i + 1);
        unsigned int expectedCapacity = hashTable.getSize() <= 4 ? hashTableDefaultCapacity : hashTableDefaultCapacity * 2;
        REQUIRE(hashTable.getCapacity() == expectedCapacity);
    }

}
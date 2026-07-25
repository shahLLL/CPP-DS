#include <catch2/catch_test_macros.hpp>
#include "../headers/dynamic_array.h"

TEST_CASE("DYNAMIC ARRAY TEST CASE #1", "[dynamic_array]") {
    DynamicArray<int> intArr = DynamicArray<int>();
    REQUIRE(intArr.getSize() == 0);
    REQUIRE(intArr.getCapacity() == defaultCapacity);
    REQUIRE(intArr.isEmpty());

    for(int i = 0; i < 12; i++)
        REQUIRE(!intArr.contains(i + 1));

    for(int i = 0; i < 12; i++)
        REQUIRE(intArr.append(i + 1));
    
    REQUIRE(intArr.getSize() == 12);
    REQUIRE(intArr.getCapacity() == defaultCapacity * 2);
    REQUIRE(!intArr.isEmpty());

    for(int i = 0; i < 12; i++)
        REQUIRE(intArr.contains(i + 1));
    
    for(int i = 15; i < 18; i++)
        REQUIRE(!intArr.remove(i));

    for(int i = 0; i < 12; i++)
        REQUIRE(intArr.remove(i + 1));
    
    for(int i = 0; i < 12; i++)
        REQUIRE(!intArr.contains(i + 1));

    REQUIRE(intArr.getSize() == 0);
    REQUIRE(intArr.getCapacity() == defaultCapacity * 2);
    REQUIRE(intArr.isEmpty());
}
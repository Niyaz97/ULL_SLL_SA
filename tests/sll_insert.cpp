#include <SortedLinkedList.hpp>
#include "catch.hpp"


SCENARIO("inserting an element => count of elements increases by the number of insertions")
{
    GIVEN("sorted linked list and its size")
    {
        sortedlist s;
        s.insert(32,83);
        s.insert(2, 36);
        auto count = s.count();

        WHEN("inserting an element")
        {
            s.insert(4,12);
            s.insert(43, 324);
            s.insert(10,352);
            THEN("count of elements increases by the number of insertions")
            {
                REQUIRE(s.count() == count + 3);
            }
        }
    }
}
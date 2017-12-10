#include <SortedArray.hpp>
#include "catch.hpp"


SCENARIO("inserting an element in sorted array => count of elements increases by the number of insertions")
{
    GIVEN("sorted array and its size")
    {
        sortedarray sa;
        sa.insert(32,83);
        sa.insert(2, 36);
        auto size = sa.count();

        WHEN("inserting an element")
        {
            sa.insert(4,12);
            sa.insert(43, 324);
            sa.insert(10,352);
            THEN("count of elements increases by the number of insertions")
            {
                REQUIRE(sa.count() == size + 3);
            }
        }
    }
}
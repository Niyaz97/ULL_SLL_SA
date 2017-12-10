#include <SortedArray.hpp>
#include "catch.hpp"


SCENARIO("find min in sorted array")
{
    GIVEN("sorted array")
    {
        sortedarray sa;
        sa.insert(3,823);
        sa.insert(-24,-92);
        sa.insert(30,8);
        sa.insert(649,36);

        WHEN("search min")
        {
            int min = sa.findmin();

            THEN("return min")
            {
                REQUIRE(min == -24);
            }
        }
    }
}

SCENARIO("find max in sorted array")
{
    GIVEN("sorted array")
    {
        sortedarray sa;
        sa.insert(3,823);
        sa.insert(-24,-92);
        sa.insert(30,8);
        sa.insert(649,36);

        WHEN("search max")
        {
            int max = sa.findmax();

            THEN("return min")
            {
                REQUIRE(max == 649);
            }
        }
    }
}
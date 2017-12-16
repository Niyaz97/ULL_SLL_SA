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
            int key = sa.findmin().first;
            int data = sa.findmin().second;

            THEN("return min")
            {
                REQUIRE(key == -24);
                REQUIRE(data == -92);
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
            int key = sa.findmax().first;
            int data = sa.findmax().second;

            THEN("return max")
            {
                REQUIRE(key == 649);
                REQUIRE(data == 36);
            }
        }
    }
}
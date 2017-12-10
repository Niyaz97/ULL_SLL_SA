#include <UnrolledLinkedList.hpp>
#include "catch.hpp"


SCENARIO("find min in unrolled list")
{
    GIVEN("unrolled list")
    {
        unrolledlist ull;
        ull.insert(-49,36);
        ull.insert(3,823);
        ull.insert(24,-92);
        ull.insert(30,8);


        WHEN("search min")
        {
            int min = ull.findmin();

            THEN("return min")
            {
                REQUIRE(min == -49);
            }
        }
    }
}

SCENARIO("find max in unrolled list")
{
    GIVEN("unrolled list")
    {
        unrolledlist ull;
        ull.insert(3,823);
        ull.insert(-24,-92);
        ull.insert(30,8);
        ull.insert(649,36);

        WHEN("search max")
        {
            int max = ull.findmax();

            THEN("return min")
            {
                REQUIRE(max == 649);
            }
        }
    }
}
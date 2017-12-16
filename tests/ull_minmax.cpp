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
            int key = ull.findmin().first;
            int data = ull.findmin().second;

            THEN("return min")
            {
                REQUIRE(key == -49);
                REQUIRE(data == 36);
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

        WHEN("search max")
        {
            int key = ull.findmax().first;
            int data = ull.findmax().second;

            THEN("return max")
            {
                REQUIRE(key == 30);
                REQUIRE(data == 8);
            }
        }
    }
}
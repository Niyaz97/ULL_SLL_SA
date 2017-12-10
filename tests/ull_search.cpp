#include <UnrolledLinkedList.hpp>
#include "catch.hpp"


SCENARIO("search an element in unrolled list")
{
    GIVEN("unrolled list")
    {
        unrolledlist ull;
        ull.insert(3,823);
        ull.insert(-24,-92);
        ull.insert(30,8);
        ull.insert(-432,36);

        WHEN("search for the element")
        {
            int key = ull.search(30);

            THEN("return found element")
            {
                REQUIRE(key == 30);
            }
        }
    }
}

SCENARIO("search an element in empty unrolled list")
{
    GIVEN("empty unrolled list")
    {
        unrolledlist ull;

        WHEN("trying to find an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(ull.search(21), std::logic_error);
            }
        }
    }
}

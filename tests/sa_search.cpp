#include <SortedArray.hpp>
#include "catch.hpp"


SCENARIO("search an element in sorted array")
{
    GIVEN("sorted array")
    {
        sortedarray sa;
        sa.insert(3,823);
        sa.insert(-24,-92);
        sa.insert(30,8);
        sa.insert(-432,36);

        WHEN("search for the element")
        {
            int key = sa.search(3).first;
            int data = sa.search(3).second;

            THEN("return found element")
            {
                REQUIRE(key == 3);
                REQUIRE(data == 823);
            }
        }
    }
}

SCENARIO("search an element in empty sorted array")
{
    GIVEN("empty sorted array")
    {
        sortedarray sa;

        WHEN("trying to find an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(sa.search(21), std::logic_error);
            }
        }
    }
}

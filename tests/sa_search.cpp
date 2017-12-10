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
            size_t key_idx = sa.binarysearch(30);

            THEN("return index of found element")
            {
                REQUIRE(key_idx == 3);
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
                REQUIRE_THROWS_AS(sa.binarysearch(21), std::logic_error);
            }
        }
    }
}

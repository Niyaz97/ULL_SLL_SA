#include <SortedArray.hpp>
#include "catch.hpp"


SCENARIO("removing an element from sorted array => count of elements decreases by one")
{
    GIVEN("sorted array and its size")
    {
        sortedarray sa;
        sa.insert(3,823);
        sa.insert(-24,-92);
        sa.insert(30,8);
        sa.insert(-432,36);
        auto size = sa.count();

        WHEN("remove an element")
        {
            sa.remove(30);

            THEN("count of elements decreased by one")
            {
                REQUIRE(sa.count() == size - 1);
            }
        }
    }
}

SCENARIO("sorted array is empty => remove method throws an exception")
{
    GIVEN("empty sorted array")
    {
        sortedarray sa;

        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(sa.remove(324), std::logic_error);
            }
        }
    }
}


SCENARIO("removing element that doesn't exist => remove method throws an exception")
{
    GIVEN("sorted array")
    {
        sortedarray sa;
        sa.insert(3,823);
        sa.insert(-24,-92);
        sa.insert(30,8);
        sa.insert(-432,36);
        WHEN("trying to remove non-existing element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(sa.remove(324), std::logic_error);
            }
        }
    }
}
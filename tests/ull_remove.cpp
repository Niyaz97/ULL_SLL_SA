#include <UnrolledLinkedList.hpp>
#include "catch.hpp"


SCENARIO("removing an element from unrolled list => count of elements decreases by one")
{
    GIVEN("unrolled list and its size")
    {
        unrolledlist ull;
        ull.insert(3,823);
        ull.insert(-24,-92);
        ull.insert(30,8);
        ull.insert(-432,36);
        auto size = ull.count();

        WHEN("remove an element")
        {
            ull.remove(30);

            THEN("count of elements decreased by one")
            {
                REQUIRE(ull.count() == size - 1);
            }
        }
    }
}

SCENARIO("unrolled list is empty => remove method throws an exception")
{
    GIVEN("empty unrolled list")
    {
        unrolledlist ull;

        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(ull.remove(324), std::logic_error);
            }
        }
    }
}
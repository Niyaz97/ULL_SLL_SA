#include <UnrolledLinkedList.hpp>
#include "catch.hpp"


SCENARIO("inserting an element in unrolled list with default block size => number of elements increases by the number of insertions")
{
    GIVEN("unrolled list with default block  size and number of elements")
    {
        unrolledlist ull;
        ull.insert(32,83);
        ull.insert(2, 36);
        ull.insert(-24,12);
        auto size = ull.count();

        WHEN("inserting an element")
        {
            ull.insert(8443, 324);
            ull.insert(-4,1832);
            ull.insert(43, 324);
            THEN("count of elements increases by the number of insertions")
            {
                REQUIRE(ull.count() == size + 3);
            }
        }
    }
}

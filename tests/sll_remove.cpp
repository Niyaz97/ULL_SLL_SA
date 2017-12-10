#include <SortedLinkedList.hpp>
#include "catch.hpp"


SCENARIO("removing an element from sorted linked list => count of elements decreases by one")
{
    GIVEN("stack and its size")
    {
        sortedlist s;
        s.insert(3,823);
        s.insert(-24,-92);
        s.insert(30,8);
        s.insert(-432,36);
        auto count = s.count();

        WHEN("remove an element")
        {
            s.remove(30);

            THEN("count of elements decreased by one")
            {
                REQUIRE(s.count() == count - 1);
            }
        }
    }
}

SCENARIO("sorted linked list is empty => remove method throws an exception")
{
    GIVEN("empty sorted linked list")
    {
        sortedlist s;

        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(s.remove(324), std::logic_error);
            }
        }
    }
}


SCENARIO("removing element doesn't exist => remove method throws an exception")
{
    GIVEN("sorted linked list")
    {
        sortedlist s;
        s.insert(3,823);
        s.insert(-24,-92);
        s.insert(30,8);
        s.insert(-432,36);
        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(s.remove(324), std::logic_error);
            }
        }
    }
}

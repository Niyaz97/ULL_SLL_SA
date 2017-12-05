#include <SortedLinkedList.hpp>
#include "catch.hpp"


SCENARIO("search an element in sorted linked list")
{
    GIVEN("sorted linked list")
    {
        sortedlist s;
        s.insert(3,823);
        s.insert(-24,-92);
        s.insert(30,8);
        s.insert(-432,36);

        WHEN("search for the element")
        {
            int key = s.search(30);;

            THEN("return found element")
            {
                REQUIRE(key == 30);
            }
        }
    }
}

SCENARIO("search an element in empty sorted linked list")
{
    GIVEN("empty sorted linked list")
    {
        sortedlist s;

        WHEN("trying to find an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(s.search(324), std::logic_error);
            }
        }
    }
}

#include <SortedLinkedList.hpp>
#include "catch.hpp"


SCENARIO("find min in sorted linked list")
{
    GIVEN("sorted linked list")
    {
        sortedlist s;
        s.insert(393,823);
        s.insert(-1,-92);
        s.insert(3,8);
        s.insert(49,36);

        WHEN("search min")
        {
            int key = s.findmin().first;
            int data = s.findmin().second;

            THEN("return min")
            {
                REQUIRE(key == -1);
                REQUIRE(data == -92);
            }
        }
    }
}

SCENARIO("find max in sorted linked list")
{
    GIVEN("sorted linked list")
    {
        sortedlist s;
        s.insert(38,823);
        s.insert(-27,-92);
        s.insert(21,8);
        s.insert(930,36);

        WHEN("search max")
        {
            int key = s.findmax().first;
            int data = s.findmax().second;

            THEN("return max")
            {
                REQUIRE(key == 930);
                REQUIRE(data == 36);
            }
        }
    }
}
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
            int min = s.findmin();

            THEN("return min")
            {
                REQUIRE(min == -1);
            }
        }
    }
}

//SCENARIO("find min element in empty sorted linked list")
//{
//    GIVEN("empty sorted linked list")
//    {
//        sortedlist s;
//
//        WHEN("trying to find min")
//        {
//            THEN("an exception must be thrown")
//            {
//                REQUIRE_THROWS_AS(s.findmin, std::logic_error);
//            }
//        }
//    }
//}


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
            int max = s.findmax();

            THEN("return min")
            {
                REQUIRE(max == 930);
            }
        }
    }
}
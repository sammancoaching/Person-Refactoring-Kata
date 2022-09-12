#include "ApprovalTests.hpp"
#include "doctest/doctest.h"

#include "Person.h"

using namespace std;

TEST_CASE ("Person") {

    string swedishPersonalNumber = "19511111-7668";
    int role = USER_ROLE_MANAGER;
    string phoneNumber = "00467123456";


    SUBCASE("birthYear") {
        auto person = Person(role, swedishPersonalNumber, phoneNumber);
        REQUIRE(1951 == person.birthYear());
    }
    SUBCASE("countryCode leading zeros") {
        auto person = Person(role, swedishPersonalNumber, phoneNumber);
        REQUIRE("+46" == person.countryCode());
    }
    SUBCASE("countryCode plus sign") {
        auto person = Person(role, swedishPersonalNumber, "+467123456");
        REQUIRE("+46" == person.countryCode());
    }
    SUBCASE("countryCode local number") {
        auto person = Person(role, swedishPersonalNumber, "07123456");
        REQUIRE("" == person.countryCode());
    }
    SUBCASE("managers can delete users") {
        auto person = Person(role, swedishPersonalNumber, "07123456");
        REQUIRE(person.canDeleteUsers());
    }
    SUBCASE("admin can delete users") {
        auto person = Person(USER_ROLE_ADMIN, swedishPersonalNumber, "07123456");
        REQUIRE(person.canDeleteUsers());
    }
    SUBCASE("engineers can't delete users") {
        auto person = Person(USER_ROLE_ENGINEER, swedishPersonalNumber, "07123456");
        REQUIRE(false == person.canDeleteUsers());
    }
    SUBCASE("sales can't delete users") {
        auto person = Person(USER_ROLE_SALES, swedishPersonalNumber, "07123456");
        REQUIRE(false == person.canDeleteUsers());
    }
}



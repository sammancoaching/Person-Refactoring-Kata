#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

#include "Person.h"

using namespace std;


TEST_CASE ("Person") {

    string swedishPersonalNumber = "19511111-7668";
    int role = USER_ROLE_MANAGER;
    string phoneNumber = "00467123456";

    SECTION("birthYear") {
        auto person = Person(role, swedishPersonalNumber, phoneNumber);
        REQUIRE(1951 == person.birthYear());
    }
    SECTION("countryCode leading zeros") {
        auto person = Person(role, swedishPersonalNumber, phoneNumber);
        REQUIRE("+46" == person.countryCode());
    }
    SECTION("countryCode plus sign") {
        auto person = Person(role, swedishPersonalNumber, "+467123456");
        REQUIRE("+46" == person.countryCode());
    }
    SECTION("countryCode local number") {
        auto person = Person(role, swedishPersonalNumber, "07123456");
        REQUIRE("" == person.countryCode());
    }
    SECTION("managers can delete users") {
        auto person = Person(role, swedishPersonalNumber, "07123456");
        REQUIRE(person.canDeleteUsers());
    }
    SECTION("admin can delete users") {
        auto person = Person(USER_ROLE_ADMIN, swedishPersonalNumber, "07123456");
        REQUIRE(person.canDeleteUsers());
    }
    SECTION("engineers can't delete users") {
        auto person = Person(USER_ROLE_ENGINEER, swedishPersonalNumber, "07123456");
        REQUIRE(false == person.canDeleteUsers());
    }
    SECTION("sales can't delete users") {
        auto person = Person(USER_ROLE_SALES, swedishPersonalNumber, "07123456");
        REQUIRE(false == person.canDeleteUsers());
    }

}



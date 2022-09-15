#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
#include "Person.h"
}

using namespace std;

TEST_CASE ("Person") {

    string swedishPersonalNumber = "19511111-7668";
    int role = USER_ROLE_MANAGER;
    string phoneNumber = "00467123456";

    SECTION("birthYear") {
        auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
        REQUIRE(1951 == birthYear(person));
    }
    SECTION("countryCode leading zeros") {
        auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
        REQUIRE("+46" == string(countryCode(person)));
    }
    SECTION("countryCode plus sign") {
        char* phoneNumber = "+467123456";
        auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
        REQUIRE("+46" == string(countryCode(person)));
    }
    SECTION("countryCode local number") {
        char* phoneNumber = "07123456";
        auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
        REQUIRE("" == string(countryCode(person)));
    }
    SECTION("managers can delete users") {
        auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
        REQUIRE(canDeleteUsers(person));
    }
    SECTION("admin can delete users") {
        auto person = Person_create(USER_ROLE_ADMIN, swedishPersonalNumber, phoneNumber);
        REQUIRE(canDeleteUsers(person));
    }
    SECTION("engineers can't delete users") {
        auto person = Person_create(USER_ROLE_ENGINEER, swedishPersonalNumber, phoneNumber);
        REQUIRE(false == canDeleteUsers(person));
    }
    SECTION("sales can't delete users") {
        auto person = Person_create(USER_ROLE_SALES, swedishPersonalNumber, phoneNumber);
        REQUIRE(false == canDeleteUsers(person));
    }

}



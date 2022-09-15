#include <gtest/gtest.h>

extern "C"
{
#include "Person.h"
}

using namespace std;


char* swedishPersonalNumber = "19511111-7668";
ROLES role = USER_ROLE_MANAGER;
char* phoneNumber = "00467123456";



TEST(PersonTestSuite, birthYear) {
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(1951, birthYear(person));
}

TEST(PersonTestSuite, countryCodeLeadingZeros) {
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ("+46", string(countryCode(person)));
}

TEST(PersonTestSuite, countryCodePlusSign) {
    char* phoneNumber = "+467123456";
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ("+46", string(countryCode(person)));
}

TEST(PersonTestSuite, localNumber) {
    char* phoneNumber = "07123456";
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ("", string(countryCode(person)));
}

TEST(PersonTestSuite, managersCanDeleteUsers) {
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(true, canDeleteUsers(person));
}

TEST(PersonTestSuite, adminCanDeleteUsers) {
    auto person = Person_create(USER_ROLE_ADMIN, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(true, canDeleteUsers(person));
}
TEST(PersonTestSuite, engineersCantDeleteUsers) {
    auto person = Person_create(USER_ROLE_ENGINEER, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(false, canDeleteUsers(person));
}
TEST(PersonTestSuite, salesCantDeleteUsers) {
    auto person = Person_create(USER_ROLE_SALES, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(false, canDeleteUsers(person));
}



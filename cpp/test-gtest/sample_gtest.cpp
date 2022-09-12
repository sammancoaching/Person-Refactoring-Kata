#include <gtest/gtest.h>

#include "Person.h"

using namespace std;

string swedishPersonalNumber = "19511111-7668";
int role = USER_ROLE_MANAGER;
string phoneNumber = "00467123456";


TEST(PersonTestSuite, birthYear) {
    auto person = Person(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(1951, person.birthYear());
}

TEST(PersonTestSuite, countryCodeLeadingZeros) {
    auto person = Person(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ("+46", person.countryCode());
}

TEST(PersonTestSuite, countryCodePlusSign) {
    auto person = Person(role, swedishPersonalNumber, "+467123456");
    ASSERT_EQ("+46", person.countryCode());
}

TEST(PersonTestSuite, localNumber) {
    auto person = Person(role, swedishPersonalNumber, "07123456");
    ASSERT_EQ("", person.countryCode());
}

TEST(PersonTestSuite, managersCanDeleteUsers) {
    auto person = Person(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(true, person.canDeleteUsers());
}

TEST(PersonTestSuite, adminCanDeleteUsers) {
    auto person = Person(USER_ROLE_ADMIN, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(true, person.canDeleteUsers());
}
TEST(PersonTestSuite, engineersCantDeleteUsers) {
    auto person = Person(USER_ROLE_ENGINEER, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(false, person.canDeleteUsers());
}
TEST(PersonTestSuite, salesCantDeleteUsers) {
    auto person = Person(USER_ROLE_SALES, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(false, person.canDeleteUsers());
}
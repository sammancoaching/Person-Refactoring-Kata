#include <gtest/gtest.h>

extern "C"
{
#include "Person.h"
}

using namespace std;

class PersonTest  : public ::testing::Test {
public:
    char* swedishPersonalNumber = "19511111-7668";
    ROLES role = USER_ROLE_MANAGER;
    char* phoneNumber = "00467123456";
    char code[4];

};



TEST_F(PersonTest, birthYear) {
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(1951, birthYear(person));
}

TEST_F(PersonTest, countryCodeLeadingZeros) {
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    countryCode(person, code);
    ASSERT_EQ("+46", string(code));
}

TEST_F(PersonTest, countryCodePlusSign) {
    char* phoneNumber = "+467123456";
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    countryCode(person, code);
    ASSERT_EQ("+46", string(code));
}

TEST_F(PersonTest, localNumber) {
    char* phoneNumber = "07123456";
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    countryCode(person, code);
    ASSERT_EQ("", string(code));
}

TEST_F(PersonTest, managersCanDeleteUsers) {
    auto person = Person_create(role, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(true, canDeleteUsers(person));
}

TEST_F(PersonTest, adminCanDeleteUsers) {
    auto person = Person_create(USER_ROLE_ADMIN, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(true, canDeleteUsers(person));
}
TEST_F(PersonTest, engineersCantDeleteUsers) {
    auto person = Person_create(USER_ROLE_ENGINEER, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(false, canDeleteUsers(person));
}
TEST_F(PersonTest, salesCantDeleteUsers) {
    auto person = Person_create(USER_ROLE_SALES, swedishPersonalNumber, phoneNumber);
    ASSERT_EQ(false, canDeleteUsers(person));
}



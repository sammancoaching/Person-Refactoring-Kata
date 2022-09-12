#include <utility>



#ifndef CPP_PERSON_H
#define CPP_PERSON_H

using namespace std;

enum ROLES {
    USER_ROLE_MANAGER,
    USER_ROLE_ENGINEER,
    USER_ROLE_ADMIN,
    USER_ROLE_SALES
};

class Person {

public:
    Person(int role, string personalNumber, string phoneNumber):
    _role(role),
    _personalNumber(std::move(personalNumber)),
    _phoneNumber(std::move(phoneNumber))
    {};

    int birthYear();

    string countryCode();

    bool canDeleteUsers();

private:
    int _role;
    string _personalNumber;
    string _phoneNumber;
};


#endif //CPP_PERSON_H

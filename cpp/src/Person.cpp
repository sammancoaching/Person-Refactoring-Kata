

#include <string>
#include "Person.h"


int Person::birthYear() {
    auto year = _personalNumber.substr(0, 4);
    return stoi(year);
}

string Person::countryCode() {
    string code;
    if (_phoneNumber.rfind("00", 0) == 0)
        code = _phoneNumber.substr(2, 2);
    else if (_phoneNumber.rfind('+', 0) == 0)
        code = _phoneNumber.substr(1,2);
    if (!code.empty())
        return "+" + code;
    return "";
}

bool Person::canDeleteUsers() {
    return _role == USER_ROLE_MANAGER || _role == USER_ROLE_ADMIN;
    ;
}

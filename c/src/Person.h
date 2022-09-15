#ifndef PERSON_H
#define PERSON_H

#include <stdbool.h>

#define PERSONAL_NUMBER_LENGTH 12
#define MAX_PHONE_LENGTH 20


enum ROLES {
    USER_ROLE_MANAGER,
    USER_ROLE_ENGINEER,
    USER_ROLE_ADMIN,
    USER_ROLE_SALES
};

struct Person {
    int role;
    char personalNumber[PERSONAL_NUMBER_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
};

struct
Person* Person_create(int role, char* personalNumber, char* phoneNumber);

int
birthYear(struct Person* person);

char*
countryCode(struct Person* person);

bool
canDeleteUsers(struct Person* person);

#endif //PERSON_H

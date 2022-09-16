#include "Person.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Person* Person_create(int role, char *personalNumber, char *phoneNumber) {
    struct Person* person = malloc(sizeof(struct Person));
    person->role = role;
    strncpy(person->personalNumber, personalNumber, sizeof(person->personalNumber) - 1);
    strncpy(person->phoneNumber, phoneNumber, sizeof(person->phoneNumber) - 1);
    return person;
}

int
birthYear(struct Person *person) {
    char birthYear[5];
    memcpy(birthYear, &person->personalNumber, 4);
    birthYear[4] = '\0';
    return atoi(birthYear);
}

bool
prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

void
countryCode(struct Person *person, char* code) {
    char* pre1 = "00";
    char* pre2 = "+";
    if (prefix(pre1, person->phoneNumber)) {
        code[0] = '+';
        code[1] = person->phoneNumber[2];
        code[2] = person->phoneNumber[3];
        code[3] = '\0';
    } else if (prefix(pre2, person->phoneNumber)) {
        code[0] = '+';
        code[1] = person->phoneNumber[1];
        code[2] = person->phoneNumber[2];
        code[3] = '\0';
    } else {
        code[0] = '\0';
    }
}

bool
canDeleteUsers(struct Person *person) {
    return person->role == USER_ROLE_MANAGER || person->role == USER_ROLE_ADMIN;
}

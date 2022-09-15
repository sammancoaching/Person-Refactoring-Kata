#include "Person.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Person *Person_create(int role, char *personalNumber, char *phoneNumber) {
    struct Person* person = malloc(sizeof(*person));
    person->role = role;
    strncpy(person->personalNumber, personalNumber, sizeof(person->personalNumber) - 1);
    strncpy(person->phoneNumber, phoneNumber, sizeof(person->phoneNumber) - 1);
    return person;
}

int birthYear(struct Person *person) {
    char birthYear[5];
    memcpy(birthYear, &person->personalNumber, 4);
    birthYear[4] = '\0';
    return atoi(birthYear);
}

bool prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

char *countryCode(struct Person *person) {
    char code[4];
    char* pre1 = "00";
    char pre2 = '+';
    if (prefix(pre1, person->phoneNumber)) {
        memcpy(code, &person->phoneNumber, 4);
        code[4] = '\0';
    } else if (prefix(pre2, person->phoneNumber)) {
        memcpy(code, &person->phoneNumber, 3);
        code[3] = '\0';
    } else {
       code[0] = '\0';
    }
    return code;
}

bool canDeleteUsers(struct Person *person) {
    return person->role == USER_ROLE_MANAGER || person->role == USER_ROLE_ADMIN;
}

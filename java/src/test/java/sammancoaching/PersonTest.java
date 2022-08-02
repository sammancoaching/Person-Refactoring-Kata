package sammancoaching;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class PersonTest {
    String swedishPersonalNumber = "19511111-7668";
    int role = Person.USER_ROLE_MANAGER;
    String phoneNumber = "00467123456";
    @Test
    void birthYear() {
        Person person = new Person(role, swedishPersonalNumber, phoneNumber);
        assertEquals(1951, person.birthYear());
    }
    @Test
    void countryCode() {
        Person person = new Person(role, swedishPersonalNumber, phoneNumber);

        assertEquals("+46", person.countryCode());
    }

    @Test
    void managersCanDeleteUsers() {
        Person person = new Person(role, swedishPersonalNumber, phoneNumber);
        assertEquals(true, person.canDeleteUsers());
    }
    @Test
    void adminCanDeleteUsers() {
        Person person = new Person(Person.USER_ROLE_ADMIN, swedishPersonalNumber, phoneNumber);
        assertEquals(true, person.canDeleteUsers());
    }
    @Test
    void salesCantDeleteUsers() {
        Person person = new Person(Person.USER_ROLE_SALES, swedishPersonalNumber, phoneNumber);
        assertEquals(false, person.canDeleteUsers());
    }
    @Test
    void engineersCantDeleteUsers() {
        Person person = new Person(Person.USER_ROLE_ENGINEER, swedishPersonalNumber, phoneNumber);
        assertEquals(false, person.canDeleteUsers());
    }

    @Test
    void standardizePhoneNumber() {
        Person person = new Person(role, swedishPersonalNumber, "+46123456");
        assertEquals("+46", person.countryCode());
    }
    @Test
    void standardizeLocalPhoneNumber() {
        Person person = new Person(role, swedishPersonalNumber, "0123456");
        assertEquals("", person.countryCode());
    }

}

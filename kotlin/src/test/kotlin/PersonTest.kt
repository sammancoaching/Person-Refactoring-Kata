import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test
import sammancoaching.Person

internal class PersonTest {
    private val swedishPersonalNumber = "19511111-7668"
    private val role: Int = Person.USER_ROLE_MANAGER
    private val phoneNumber = "00467123456"

    @Test
    fun birthYear() {
        val person = Person(role, swedishPersonalNumber, phoneNumber)
        assertEquals(1951, person.birthYear())
    }

    @Test
    fun countryCode() {
        val person = Person(role, swedishPersonalNumber, phoneNumber)
        assertEquals("+46", person.countryCode())
    }

    @Test
    fun managersCanDeleteUsers() {
        val person = Person(role, swedishPersonalNumber, phoneNumber)
        assertTrue(person.canDeleteUsers())
    }

    @Test
    fun adminCanDeleteUsers() {
        val person = Person(Person.USER_ROLE_ADMIN, swedishPersonalNumber, phoneNumber)
        assertTrue(person.canDeleteUsers())
    }

    @Test
    fun salesCantDeleteUsers() {
        val person = Person(Person.USER_ROLE_SALES, swedishPersonalNumber, phoneNumber)
        assertFalse(person.canDeleteUsers())
    }

    @Test
    fun engineersCantDeleteUsers() {
        val person = Person(Person.USER_ROLE_ENGINEER, swedishPersonalNumber, phoneNumber)
        assertFalse(person.canDeleteUsers())
    }

    @Test
    fun standardizePhoneNumber() {
        val person = Person(role, swedishPersonalNumber, "+46123456")
        assertEquals("+46", person.countryCode())
    }

    @Test
    fun standardizeLocalPhoneNumber() {
        val person = Person(role, swedishPersonalNumber, "0123456")
        assertEquals("", person.countryCode())
    }
}

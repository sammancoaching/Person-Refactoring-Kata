import unittest
from person import Person


class PersonTest(unittest.TestCase):
    def setUp(self):
        self.swedish_personal_number: str = "19511111-7668"
        self.role: int = Person.USER_ROLE_MANAGER
        self.phone_number: str = "00467123456"

    def test_birth_year(self):
        person = Person(self.role, self.swedish_personal_number, self.phone_number)
        assert 1951 == person.birth_year()

    def test_country_code(self):
        person = Person(self.role, self.swedish_personal_number, self.phone_number)

        assert "+46" == person.country_code()

    def test_managers_can_delete_users(self):
        person = Person(self.role, self.swedish_personal_number, self.phone_number)
        assert person.can_delete_users()

    def test_admin_can_delete_users(self):
        person = Person(
            Person.USER_ROLE_ADMIN, self.swedish_personal_number, self.phone_number
        )
        assert person.can_delete_users()

    def test_sales_cant_delete_users(self):
        person = Person(
            Person.USER_ROLE_SALES, self.swedish_personal_number, self.phone_number
        )
        assert not person.can_delete_users()

    def test_engineers_cant_delete_users(self):
        person = Person(
            Person.USER_ROLE_ENGINEER, self.swedish_personal_number, self.phone_number
        )
        assert not person.can_delete_users()

    def test_standardize_phone_number(self):
        person = Person(self.role, self.swedish_personal_number, "+46123456")
        assert "+46" == person.country_code()

    def test_standardize_local_phone_number(self):
        person = Person(self.role, self.swedish_personal_number, "0123456")
        assert "" == person.country_code()


if __name__ == "__main__":
    unittest.main()

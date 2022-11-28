import unittest

from person import Person


class PersonTestCase(unittest.TestCase):

    def setUp(self) -> None:
        self.swedish_personal_number = "19511111-7668"
        self.role = Person.USER_ROLE_MANAGER
        self.phone_number = "00467123456"
        super().setUp()

    def test_birth_year(self):
        person = Person(self.role, self.swedish_personal_number, self.phone_number)
        self.assertEqual(1951, person.birth_year())

    def test_country_code(self):
        person = Person(self.role, self.swedish_personal_number, self.phone_number)
        self.assertEqual("+46", person.country_code())

    def test_managers_can_delete_users(self):
        person = Person(self.role, self.swedish_personal_number, self.phone_number)
        self.assertTrue(person.can_delete_users())

    def test_admins_can_delete_users(self):
        person = Person(Person.USER_ROLE_ADMIN, self.swedish_personal_number, self.phone_number)
        self.assertTrue(person.can_delete_users())

    def test_sales_can_not_delete_users(self):
        person = Person(Person.USER_ROLE_SALES, self.swedish_personal_number, self.phone_number)
        self.assertFalse(person.can_delete_users())

    def test_engineers_can_not_delete_users(self):
        person = Person(Person.USER_ROLE_ENGINEER, self.swedish_personal_number, self.phone_number)
        self.assertFalse(person.can_delete_users())

    def test_standardize_phone_number(self):
        person = Person(self.role, self.swedish_personal_number, "+46123456")
        self.assertEqual("+46", person.country_code())

    def test_standardize_local_phone_number(self):
        person = Person(self.role, self.swedish_personal_number, "0123456")
        self.assertEqual("", person.country_code())


if __name__ == '__main__':
    unittest.main()

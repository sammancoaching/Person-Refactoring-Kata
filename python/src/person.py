class Person:
    USER_ROLE_ADMIN: int = 0
    USER_ROLE_ENGINEER: int = 1
    USER_ROLE_MANAGER: int = 2
    USER_ROLE_SALES: int = 3

    def __init__(self, role: int, swedish_personal_number: str, phone_number: str):
        self.set_role(role)
        self.set_swedish_personal_number(swedish_personal_number)
        self._phone_number = phone_number

    def get_role(self) -> int:
        return self._role

    def set_role(self, role: int):
        if role < 0 or role > 4:
            raise ValueError(f"illegal role {role}")
        self._role = role

    def get_swedish_personal_number(self) -> str:
        return self._swedish_personal_number

    def set_swedish_personal_number(self, swedish_personal_number: str):
        swedish_personal_number = swedish_personal_number.replace("-", "")
        if len(swedish_personal_number) != 12:
            raise ValueError(f"invalid personal number {swedish_personal_number}")
        self._swedish_personal_number = swedish_personal_number

    def get_phone_number(self) -> str:
        return self._phone_number

    def set_phone_number(self, phone_number: str):
        self._phone_number = phone_number

    def birth_year(self) -> int:
        year = self._swedish_personal_number[0:4]
        return int(year)

    def country_code(self) -> str:
        code = ""
        if self._phone_number.startswith("00"):
            code = self._phone_number[2:4]
        elif self._phone_number.startswith("+"):
            code = self._phone_number[1:3]
        if code:
            return f"+{code}"
        return ""

    def can_delete_users(self) -> bool:
        return self._role in [Person.USER_ROLE_MANAGER, Person.USER_ROLE_ADMIN]

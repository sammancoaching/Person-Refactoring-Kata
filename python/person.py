class Person:
    USER_ROLE_ADMIN = 0
    USER_ROLE_ENGINEER = 1
    USER_ROLE_MANAGER = 2
    USER_ROLE_SALES = 3

    def __init__(self, role: int, swedish_personal_number: str, phone_number: str):
        self.role = role
        self.set_role(role)
        self.swedish_personal_number = swedish_personal_number
        self.set_swedish_personal_number(swedish_personal_number)
        self.phone_number = phone_number

    def get_role(self) -> int:
        return self.role

    def set_role(self, role):
        if role < 0 or role > 4:
            raise ValueError("illegal role " + role)
        self.role = role

    def get_swedish_personal_number(self) -> str:
        return self.swedish_personal_number

    def set_swedish_personal_number(self, swedish_personal_number):
        swedish_personal_number = swedish_personal_number.replace("-", "")
        if swedish_personal_number.__len__() != 12:
            raise ValueError("invalid personal number " + swedish_personal_number)
        self.swedish_personal_number = swedish_personal_number

    def get_phone_number(self) -> str:
        return self.phone_number

    def set_phone_number(self, phone_number: str):
        self.phone_number = phone_number

    def birth_year(self) -> int:
        year = self.swedish_personal_number[0:4]
        return int(year)

    def country_code(self) -> str:
        code = ""
        if self.phone_number.startswith("00"):
            code = self.phone_number[2:4]
        elif self.phone_number.startswith("+"):
            code = self.phone_number[1:3]
        if code != "":
            return "+" + code
        return ""

    def can_delete_users(self) -> bool:
        return self.role == Person.USER_ROLE_MANAGER or self.role == Person.USER_ROLE_ADMIN

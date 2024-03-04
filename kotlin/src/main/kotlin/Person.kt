package sammancoaching

import java.time.Year

class Person(
    private val role: Role,
    private val swedishPersonalNumber: SwedishPersonalNumber,
    private val phoneNumber: PhoneNumber,
    private val birthYear: Year
) {

    companion object {
        fun createFromSwedishPersonalNumber(role: Role, swedishPersonalNumber: String, phoneNumber: String): Person {
            return Person(
                role,
                SwedishPersonalNumber.of(swedishPersonalNumber),
                PhoneNumber(phoneNumber),
                SwedishPersonalNumber.parseYear(swedishPersonalNumber)
            )
        }
    }

    fun birthYear(): Int {
        return birthYear
    }

    fun countryCode(): String {
        return phoneNumber.countryCode()
    }

    fun canDeleteUsers(): Boolean {
        return role.canDeleteUsers()
    }

    enum class Role {
        ADMIN,
        ENGINEER,
        MANAGER,
        SALES;

        fun canDeleteUsers(): Boolean {
            return this == MANAGER || this == ADMIN
        }
    }

    data class PhoneNumber(val number: String) {
        fun countryCode(): String {
            var code = ""
            if (number.startsWith("00")) {
                code = number.substring(2, 4)
            } else if (number.startsWith("+")) {
                code = number.substring(1, 3)
            }

            if (code.isNotEmpty()) return "+$code"
            return ""
        }
    }

    data class SwedishPersonalNumber private constructor(val personalNumber: String) {
        companion object {
            fun parseYear(number: String): Year {
                return Year.parse(parseNumber(number).substring(0, 4))
            }
            fun of(number: String): SwedishPersonalNumber {
                return SwedishPersonalNumber(parseNumber(number))
            }

            private fun parseNumber(number: String): String {
                val swedishPersonalNumber = number.replace("-", "")
                require(swedishPersonalNumber.length == 12) { "invalid personal number $swedishPersonalNumber" }
                return swedishPersonalNumber
            }
        }
    }

}

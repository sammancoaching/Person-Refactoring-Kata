package sammancoaching

class Person(
    role: Int,
    swedishPersonalNumber: String,
    phoneNumber: String
) {
    private var role = 0
    var swedishPersonalNumber: String? = null
        private set
    var phoneNumber: String

    init {
        setRole(role)
        setSwedishPersonalNumber(swedishPersonalNumber)
        this.phoneNumber = phoneNumber
    }


    fun setRole(role: Int) {
        require(!(role < 0 || role > 4)) { "illegal role$role" }
        this.role = role
    }

    fun setSwedishPersonalNumber(swedishPersonalNumber: String) {
        var swedishPersonalNumber = swedishPersonalNumber
        swedishPersonalNumber = swedishPersonalNumber.replace("-", "")
        require(swedishPersonalNumber.length == 12) { "invalid personal number $swedishPersonalNumber" }
        this.swedishPersonalNumber = swedishPersonalNumber
    }

    fun birthYear(): Int {
        val year = swedishPersonalNumber!!.substring(0, 4)
        return year.toInt()
    }

    fun countryCode(): String {
        var code = ""
        if (phoneNumber.startsWith("00")) {
            code = phoneNumber.substring(2, 4)
        }
        else if (phoneNumber.startsWith("+")) {
            code = phoneNumber.substring(1, 3)
        }

        if (code.isNotEmpty()) return  "+$code"
        return ""
    }

    fun canDeleteUsers(): Boolean {
        return role == USER_ROLE_MANAGER || role == USER_ROLE_ADMIN
    }

    companion object {
        const val USER_ROLE_ADMIN = 0
        const val USER_ROLE_ENGINEER = 1
        const val USER_ROLE_MANAGER = 2
        const val USER_ROLE_SALES = 3
    }
}

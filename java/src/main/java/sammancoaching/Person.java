package sammancoaching;

public class Person {
    public static final int USER_ROLE_ADMIN = 0;
    public static final int USER_ROLE_ENGINEER = 1;
    public static final int USER_ROLE_MANAGER = 2;
    public static final int USER_ROLE_SALES = 3;

    private int role;
	private String swedishPersonalNumber;
    private String phoneNumber;

    public Person(int role, String swedishPersonalNumber, String phoneNumber) {
        setRole(role);
        setSwedishPersonalNumber(swedishPersonalNumber);
        this.phoneNumber = phoneNumber;
    }

    public int getRole() {
        return role;
    }

    public void setRole(int role) {
        if (role < 0 || role > 4)
            throw new IllegalArgumentException("illegal role" + role);
        this.role = role;
    }

    public String getSwedishPersonalNumber() {
        return swedishPersonalNumber;
    }

    public void setSwedishPersonalNumber(String swedishPersonalNumber) {
        swedishPersonalNumber = swedishPersonalNumber.replace("-", "");
        if (swedishPersonalNumber.length() != 12)
            throw new IllegalArgumentException("invalid personal number " + swedishPersonalNumber);
        this.swedishPersonalNumber = swedishPersonalNumber;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public int birthYear() {
        String year = swedishPersonalNumber.substring(0, 4);
        return Integer.parseInt(year);
    }

    public String countryCode() {
        String code = "";
        if (phoneNumber.startsWith("00"))
            code = phoneNumber.substring(2, 4);
        else if (phoneNumber.startsWith("+"))
            code = phoneNumber.substring(1,3);
        if (!code.isEmpty())
            return "+" + code;
        return "";
    }

    public boolean canDeleteUsers() {
        return this.role == Person.USER_ROLE_MANAGER || this.role == Person.USER_ROLE_ADMIN;
    }
}
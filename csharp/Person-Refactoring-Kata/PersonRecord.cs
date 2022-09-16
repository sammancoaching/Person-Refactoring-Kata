namespace Person_Refactoring_Kata;


public class PersonRecord
{
    public static int USER_ROLE_ADMIN = 0;
    public static int USER_ROLE_ENGINEER = 1;
    public static int USER_ROLE_MANAGER = 2;
    public static int USER_ROLE_SALES = 3;
    public int Role { get; }
    public string SwedishPersonalNumber { get; }
    public string PhoneNumber { get; }
    
    public PersonRecord(int role, string swedishPersonalNumber, string phoneNumber)
    {
        Role = role;
        SwedishPersonalNumber = swedishPersonalNumber;
        PhoneNumber = phoneNumber;
    }
    
}
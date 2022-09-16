using System.Diagnostics.SymbolStore;

namespace Person_Refactoring_Kata;

public class PersonUtil
{
    public static bool ValidatePersonalNumber(string value)
    {
        var pn = value.Replace("-", "");
        if (pn.Length != 12)
            throw new ArgumentOutOfRangeException( "personalNumber","a personal number should have length 12");
        return true;
    }

    public static bool ValidatePhoneNumber(string value)
    {
        if (value.StartsWith("+") || value.StartsWith("0"))
            return true;
        throw new ArgumentException("phonenumber must begin with + or 0");
    }

    public static bool ValidateRole(int value)
    {
        if (value < 0 || value > 4) 
            throw new ArgumentOutOfRangeException("role", "valid role is between 0..3");
        return true;
    }

    public static int BirthYear(string swedishPersonalNumber)
    {
        var year = swedishPersonalNumber.Substring(0, 4);
        int result = 0;
        int.TryParse(year, out result);
        return result;
    }

    public static string CountryCode(string phoneNumber)
    {
        String code = "";
        if (phoneNumber.StartsWith("00"))
            code = phoneNumber.Substring(2, 2);
        else if (phoneNumber.StartsWith("+"))
            code = phoneNumber.Substring(1,2);
        if (code != "")
            return "+" + code;
        return "";
    }

    public static bool CanDeleteUsers(int role)
    {
        return role == PersonRecord.USER_ROLE_MANAGER || role == PersonRecord.USER_ROLE_ADMIN;
    }
}
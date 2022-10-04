namespace Person_Refactoring_Kata;

public class DataProcessor
{
    private int _retiredCounter = 0;
    private int _swedishCounter = 0;
    private int _priviledgedCounter = 0;
    public int RetiredCounter => _retiredCounter;
    public int SwedishCounter => _swedishCounter;
    public int PriviledgedCounter => _priviledgedCounter;

    public PersonRecord ProcessRecord(string personalNumber, string phoneNumber, int role)
    {
        PersonUtil.ValidatePersonalNumber(personalNumber);
        PersonUtil.ValidatePhoneNumber(phoneNumber);
        PersonUtil.ValidateRole(role);
        var record = new PersonRecord(role, personalNumber, phoneNumber);

        // store some statistics about the records we process
        if (PersonUtil.BirthYear(personalNumber) < 1945)
        {
            // Person is retired
            _retiredCounter++;
        }

        if (PersonUtil.CountryCode(phoneNumber) == "+46")
        {
            //person has a Swedish phone
            _swedishCounter++;
        }

        if (PersonUtil.CanDeleteUsers(role))
        {
            // person is priviledged
            _priviledgedCounter++;
        }

        return record;
    }
}
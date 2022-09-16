using NUnit.Framework;
using System.Diagnostics.SymbolStore;

namespace Person_Refactoring_Kata;

[TestFixture]
public class DataProcessorTest
{
    string swedishPersonalNumber;
    int role;
    string phoneNumber;
    private DataProcessor _dataProcessor;

    [SetUp]
    public void Init()
    {
        swedishPersonalNumber = "19511111-7668";
        role = PersonRecord.USER_ROLE_MANAGER;
        phoneNumber = "00467123456";
        _dataProcessor = new DataProcessor();
    }
    
    [Test]
    public void NormalRecord()
    {
        var record = _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role);
        Assert.AreEqual(swedishPersonalNumber, record.SwedishPersonalNumber);
        Assert.AreEqual(phoneNumber, record.PhoneNumber);
        Assert.AreEqual(role, record.Role);
        Assert.AreEqual(0, _dataProcessor.RetiredCounter);
        Assert.AreEqual(1, _dataProcessor.SwedishCounter);
        Assert.AreEqual(1, _dataProcessor.PriviledgedCounter);
    }
    
    [Test]
    public void RetiredRecord()
    {
        swedishPersonalNumber = "19431111-7668";
        var record = _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role);
        Assert.AreEqual(swedishPersonalNumber, record.SwedishPersonalNumber);
        Assert.AreEqual(phoneNumber, record.PhoneNumber);
        Assert.AreEqual(role, record.Role);
        Assert.AreEqual(1, _dataProcessor.RetiredCounter);
        Assert.AreEqual(1, _dataProcessor.SwedishCounter);
        Assert.AreEqual(1, _dataProcessor.PriviledgedCounter);
    }
    
    [Test]
    public void SalesRecord()
    {
        role = PersonRecord.USER_ROLE_SALES;
        var record = _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role);
        Assert.AreEqual(swedishPersonalNumber, record.SwedishPersonalNumber);
        Assert.AreEqual(phoneNumber, record.PhoneNumber);
        Assert.AreEqual(role, record.Role);
        Assert.AreEqual(0, _dataProcessor.RetiredCounter);
        Assert.AreEqual(1, _dataProcessor.SwedishCounter);
        Assert.AreEqual(0, _dataProcessor.PriviledgedCounter);
    }
    
    [Test]
    public void NorwegianRecord()
    {
        phoneNumber = "+451234664634";
        role = PersonRecord.USER_ROLE_ENGINEER;
        var record = _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role);
        Assert.AreEqual(swedishPersonalNumber, record.SwedishPersonalNumber);
        Assert.AreEqual(phoneNumber, record.PhoneNumber);
        Assert.AreEqual(role, record.Role);
        Assert.AreEqual(0, _dataProcessor.RetiredCounter);
        Assert.AreEqual(0, _dataProcessor.SwedishCounter);
        Assert.AreEqual(0, _dataProcessor.PriviledgedCounter);
    }

    [Test]
    public void BadPersonalNumber()
    {
        swedishPersonalNumber = "bad";
        Assert.Throws<ArgumentOutOfRangeException>(() => _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role));
    }
    
    [Test]
    public void BadPhoneNumber()
    {
        phoneNumber = "bad";
        Assert.Throws<ArgumentException>(() => _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role));
    }
    
    [Test]
    public void BadRole()
    {
        role = 5;
        Assert.Throws<ArgumentOutOfRangeException>(() => _dataProcessor.processRecord(swedishPersonalNumber, phoneNumber, role));
    }
}
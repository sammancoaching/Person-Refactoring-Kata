package person

import (
	"testing"
)

const swedishPersonalNumber = "19511111-7668"
const phoneNumber = "00467123456"
const role = UserRoleManager

func TestBirthYear(t *testing.T) {
	person := NewPerson(role, swedishPersonalNumber, phoneNumber)
	if person.BirthYear() != 1951 {
		t.Errorf("person.BirthYear() = %v, want 1951", person.BirthYear())
	}
}

func TestCountryCode(t *testing.T) {
	person := NewPerson(role, swedishPersonalNumber, phoneNumber)
	if person.CountryCode() != "+46" {
		t.Errorf("person.CountryCode() = '%v', want '+46'", person.CountryCode())
	}
}

func TestManagersCanDeleteUsers(t *testing.T) {
	person := NewPerson(role, swedishPersonalNumber, phoneNumber)
	if !person.CanDeleteUsers() {
		t.Errorf("person.CanDeleteUsers() = %v, want true", person.CanDeleteUsers())
	}
}

func TestAdminsCanDeleteUsers(t *testing.T) {
	person := NewPerson(UserRoleAdmin, swedishPersonalNumber, phoneNumber)
	if !person.CanDeleteUsers() {
		t.Errorf("person.CanDeleteUsers() = %v, want true", person.CanDeleteUsers())
	}
}

func TestSalesCantDeleteUsers(t *testing.T) {
	person := NewPerson(UserRoleSales, swedishPersonalNumber, phoneNumber)
	if person.CanDeleteUsers() {
		t.Errorf("person.CanDeleteUsers() = %v, want false", person.CanDeleteUsers())
	}
}

func TestEngineersCantDeleteUsers(t *testing.T) {
	person := NewPerson(UserRoleEngineer, swedishPersonalNumber, phoneNumber)
	if person.CanDeleteUsers() {
		t.Errorf("person.CanDeleteUsers() = %v, want false", person.CanDeleteUsers())
	}
}

func TestStandardizePhoneNumber(t *testing.T) {
	person := NewPerson(role, swedishPersonalNumber, "+46123456")
	if person.CountryCode() != "+46" {
		t.Errorf("person.CountryCode() = '%v', want '+46'", person.CountryCode())
	}
}

func TestStandardizeLocalPhoneNumber(t *testing.T) {
	person := NewPerson(role, swedishPersonalNumber, "0123456")
	if person.CountryCode() != "" {
		t.Errorf("person.CountryCode() = '%v', want ''", person.CountryCode())
	}
}

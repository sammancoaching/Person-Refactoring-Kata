package person

import (
	"strconv"
	"strings"
)

const UserRoleAdmin = 0
const UserRoleEngineer = 1
const UserRoleManager = 2
const UserRoleSales = 3

type Person struct {
	role                  int
	swedishPersonalNumber string
	phoneNumber           string
}

func NewPerson(role int, swedishPersonalNumber string, phoneNumber string) *Person {
	person := &Person{}
	person.SetRole(role)
	person.SetSwedishPersonalNumber(swedishPersonalNumber)
	person.SetPhoneNumber(phoneNumber)
	return person
}

func (p *Person) Role() int {
	return p.role
}

func (p *Person) SetRole(role int) {
	if role < 0 || role > 4 {
		panic("illegal role " + strconv.Itoa(role))
	}

	p.role = role
}

func (p *Person) SwedishPersonalNumber() string {
	return p.swedishPersonalNumber
}

func (p *Person) SetSwedishPersonalNumber(swedishPersonalNumber string) {
	swedishPersonalNumber = strings.Replace(swedishPersonalNumber, "-", "", -1)
	if len(swedishPersonalNumber) != 12 {
		panic("invalid personal number " + swedishPersonalNumber)
	}

	p.swedishPersonalNumber = swedishPersonalNumber
}

func (p *Person) PhoneNumber() string {
	return p.phoneNumber
}

func (p *Person) SetPhoneNumber(phoneNumber string) {
	p.phoneNumber = phoneNumber
}

func (p *Person) BirthYear() int {
	s := p.swedishPersonalNumber[0:4]
	birthYear, _ := strconv.Atoi(s)
	return birthYear
}

func (p *Person) CountryCode() string {
	code := ""
	if strings.HasPrefix(p.phoneNumber, "00") {
		code = p.phoneNumber[2:4]
	} else if strings.HasPrefix(p.phoneNumber, "+") {
		code = p.phoneNumber[1:3]
	}
	if code != "" {
		return "+" + code
	}
	return ""
}

func (p *Person) CanDeleteUsers() bool {
	return p.role == UserRoleManager || p.role == UserRoleAdmin
}

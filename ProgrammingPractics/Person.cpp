#include "stdafx.h"
#include "Person.h"

using namespace std;

Person::Person(char* name, char* surname, int age, enum Sex sex)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(sex);
}

void Person::SetName(char* name)
{
	_name = name;
}

void Person::SetSurname(char* surname)
{
	_surname = surname;
}

void Person::SetAge(int age)
{
	_age = age;
}

void Person::SetSex(enum Sex sex)
{
	_sex = sex;
}

char* Person::GetName()
{
	return _name;
}

char* Person::GetSurname()
{
	return _surname;
}

int Person::GetAge()
{
	return _age;
}

Sex Person::GetSex()
{
	return _sex;
}
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
	if (age > 0)
	{
		_age = age;
	}
	else
	{
		_age = 1;
	}
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

char* Person::GetDescription()
{
	char* description = new char[200];
	*description = '\0';

	Concatenate(description, _name);
	Concatenate(description, " ");
	Concatenate(description, _surname);
	Concatenate(description, ", ");

	char* ageStr = new char[10];
	_itoa_s(_age, ageStr, 10, 10);
	Concatenate(description, ageStr);
	delete ageStr;

	Concatenate(description, " years old, ");
	if (_sex)
	{
		Concatenate(description, " male.");
	}
	else
	{
		Concatenate(description, " female.");
	}

	return description;
}

Person::~Person()
{
	delete _name;
	delete _surname;
};
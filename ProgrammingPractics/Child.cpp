#include "stdafx.h"
#include "Child.h"
#include "PersonTools.h"

Child::Child(char* name, char* surname, int age, Sex sex, Person* mother, Person* father)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(sex);
	SetMother(mother);
	SetFather(father);
};

void Child::SetAge(int age)
{
	if (age < 18)
	{
		_age = age;
	}
	else
	{
		_age = 17;
	}
}

void Child::SetMother(Person* mother)
{
	_mother = mother;
}

void Child::SetFather(Person* father)
{
	_father = father;
}

Person* Child::GetMother()
{
	return _mother;
}

Person* Child::GetFather()
{
	return _father;
}

char* Child::GetDescription()
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

	Concatenate(description, " ���, ");
	if (_sex)
	{
		Concatenate(description, " �������, ");
	}
	else
	{
		Concatenate(description, " �������, ");
	}

	if (_mother == nullptr && _father == nullptr)
	{
		Concatenate(description, "�������� �� �������.");
	}
	else if (_mother == nullptr)
	{
		Concatenate(description, "���� - ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, ".");
	}
	else if (_father == nullptr)
	{
		Concatenate(description, "���� - ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ".");
	}
	else
	{
		Concatenate(description, "��������: ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, " � ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ".");
	}

	return description;
}

Child* Child::GetRandom()
{
	const char* MaleNames[] = { "����", "�������", "����", "���������", "������", "�����", "�����", "������", "��������", "����������", "�������", "������" };
	const char* FemaleNames[] = { "�����", "����", "���������", "���������", "��������", "������", "�����", "������", "���������", "��������", "���������", "�����" };
	const char* MaleSurnames[] = { "�������", "�����������", "�������", "��������", "������", "�������", "��������", "������", "�������", "����������", "�������", "�������" };
	const char* FemaleSurnames[] = { "��������", "���������", "���������", "������", "������", "�������", "�������", "��������", "������", "��������", "�������", "��������" };

	char* tempName = new char[20];
	char* tempSurname = new char[20];

	int tempAge = 1 + rand() % 17;
	Sex tempSex = Sex(rand() % 2);

	Person* tempMother;
	Person* tempFather;

	if (rand() % 3)
	{
		tempMother = GetRandomPerson((Sex)0);
	}
	else
	{
		tempMother = nullptr;
	}

	if (rand() % 3)
	{
		tempFather = GetRandomPerson((Sex)1);
	}
	else
	{
		tempFather = nullptr;
	}

	if (tempSex)
	{
		CopyConstString(tempName, MaleNames[rand() % 12]);
		CopyConstString(tempSurname, MaleSurnames[rand() % 12]);
	}
	else
	{
		CopyConstString(tempName, FemaleNames[rand() % 12]);
		CopyConstString(tempSurname, FemaleSurnames[rand() % 12]);
	}
	return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather);
}
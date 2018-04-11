#include "stdafx.h"
#include "Adult.h"
#include "PersonTools.h"

Adult::Adult(char* name, char* surname, int age, enum Sex sex, Person* marriedOn, char* workPlace)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(sex);
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
};

void Adult::SetAge(int age)
{
	if (age >= 18)
	{
		_age = age;
	}
	else
	{
		_age = 18;
	}
}

void Adult::SetMarriedOn(Person* marriedOn)
{
	_marriedOn = marriedOn;
}

void Adult::SetWorkPlace(char* workPlace)
{
	_workPlace = workPlace;
}

Person* Adult::GetMarriedOn()
{
	return _marriedOn;
};

char* Adult::GetWorkPlace()
{
	return _workPlace;
};

char* Adult::GetDescription()
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
		Concatenate(description, "�������, ");
	}
	else
	{
		Concatenate(description, "�������, ");
	}
	
	if (_marriedOn == nullptr)
	{
		Concatenate(description, "�� � �����");
	}
	else
	{
		Concatenate(description, "� ����� � ");
		Concatenate(description, _marriedOn->GetName());
		Concatenate(description, " ");
		Concatenate(description, _marriedOn->GetSurname());
	}

	if (*_workPlace == '\0')
	{
		Concatenate(description, ", �����������.");
	}
	else
	{
		Concatenate(description, ", ");
		Concatenate(description, _workPlace);
		Concatenate(description, ".");
	}

	return description;
}

Adult* Adult::GetRandom()
{
	const char* MaleNames[] = { "����", "�������", "����", "���������", "������", "�����", "�����", "������", "��������", "����������", "�������", "������" };
	const char* FemaleNames[] = { "�����", "����", "���������", "���������", "��������", "������", "�����", "������", "���������", "��������", "���������", "�����" };
	const char* MaleSurnames[] = { "�������", "�����������", "�������", "��������", "������", "�������", "��������", "������", "�������", "����������", "�������", "�������" };
	const char* FemaleSurnames[] = { "��������", "���������", "���������", "������", "������", "�������", "�������", "��������", "������", "��������", "�������", "��������" };

	const char* WorkPlaces[] = { "�����������", "��������", "�������", "�����", "��������", "������", "�������", "���������", "���������" };

	char* tempName = new char[20];
	char* tempSurname = new char[20];
	char* tempWorkPlace = new char[50];

	int tempAge = 18 + rand() % 80;
	enum Sex tempSex = enum Sex(rand() % 2);

	Person* tempMarriedOn = GetRandomPerson((Sex)!tempSex);

	if (rand() % 5)
	{
		CopyConstString(tempWorkPlace, WorkPlaces[rand() % 9]);
	}
	else
	{
		*tempWorkPlace = '\0';
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
	return new Adult(tempName, tempSurname, tempAge, tempSex, tempMarriedOn, tempWorkPlace);
}
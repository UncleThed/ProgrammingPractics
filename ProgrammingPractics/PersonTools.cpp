#include "stdafx.h"
#include "PersonTools.h"
#include "strfunc.h"

using namespace std;

istream& operator >> (istream& is, Person* person)
{
	char* tempName = new char[20];
	char* tempSurname = new char[20];
	int tempAge;
	int tempSex;

	bool key = true;

	while (key)
	{
		cout << endl << "������� ���: ";
		cin >> tempName;
		key = !CheckName(tempName);
	}

	person->SetName(tempName);
	key = true;

	while (key)
	{
		cout << endl << "������� �������: ";
		cin >> tempSurname;
		key = !CheckName(tempSurname);
	}

	person->SetSurname(tempSurname);

	cout << endl << "������� ��� (0 - �������, 1 - �������): ";
	do
	{
		tempSex = EnterInteger();
	} while (tempSex != 0 && tempSex != 1);

	person->SetSex((Sex)tempSex);

	cout << endl << "������� �������: ";
	tempAge = EnterInteger();
	person->SetAge(tempAge);

	return is;
}

Person* ReadPerson()
{
	Person* person = new Person();
	cin >> person;

	return person;
}

void ShowPerson(Person* person)
{
	cout << "�������: " << person << endl;
}

Person* GetRandomPerson()
{
	const char* MaleNames[] = { "����", "�������", "����", "���������", "������", "�����", "�����", "������", "��������", "����������", "�������", "������" };
	const char* FemaleNames[] = { "�����", "����", "���������", "���������", "��������", "������", "�����", "������", "���������", "��������", "���������", "�����" };
	const char* MaleSurnames[] = { "�������", "�����������", "�������", "��������", "������", "�������", "��������", "������", "�������", "����������", "�������", "�������" };
	const char* FemaleSurnames[] = { "��������", "���������", "���������", "������", "������", "�������", "�������", "��������", "������", "��������", "�������", "��������" };

	char* tempName = new char[20];
	char* tempSurname = new char[20];
	int tempAge = 1 + rand() % 80;
	Sex tempSex = Sex(rand() % 2);

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
	return new Person(tempName, tempSurname, tempAge, tempSex);
}

Person* GetRandomPerson(Sex tempSex)
{
	const char* MaleNames[] = { "����", "�������", "����", "���������", "������", "�����", "�����", "������", "��������", "����������", "�������", "������" };
	const char* FemaleNames[] = { "�����", "����", "���������", "���������", "��������", "������", "�����", "������", "���������", "��������", "���������", "�����" };
	const char* MaleSurnames[] = { "�������", "�����������", "�������", "��������", "������", "�������", "��������", "������", "�������", "����������", "�������", "�������" };
	const char* FemaleSurnames[] = { "��������", "���������", "���������", "������", "������", "�������", "�������", "��������", "������", "��������", "�������", "��������" };

	char* tempName = new char[20];
	char* tempSurname = new char[20];
	int tempAge = 1 + rand() % 80;

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
	return new Person(tempName, tempSurname, tempAge, tempSex);
}

bool CheckName(char* name)
{
	bool isTrueName = true;
	int i = 0;
	for (; name[i]; i++)
	{
		if (name[i] < 'A' || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z')
		{
			return false;
		}
	}

	return isTrueName;
}
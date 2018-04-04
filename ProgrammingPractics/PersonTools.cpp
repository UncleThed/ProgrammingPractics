#include "stdafx.h"
#include "PersonTools.h"
#include "strcpy.h"

using namespace std;

ostream& operator << (ostream &os, Person* person)
{
	os << '(' << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex() << ')';
	return os;
}

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
		key = !CheckChar(tempName);
	}

	person->SetName(tempName);
	key = true;

	while (key)
	{
		cout << endl << "������� �������: ";
		cin >> tempSurname;
		key = !CheckChar(tempSurname);
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
	enum Sex tempSex = enum Sex(rand() % 2);

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

bool CheckChar(char* name)
{
	bool isTrueName = true;
	for (int i = 0; i < strlen(name); i++)
	{
		if (isdigit(name[i]) || isspace(name[i]))
		{
			isTrueName = false;
			break;
		}

		if (name[i] == '-')
		{
			if (islower(name[i + 1]))
			{
				name[i + 1] = toupper(name[i + 1]);
			}
			else
			{
				isTrueName = false;
				break;
			}
		}
	}
	return isTrueName;
}
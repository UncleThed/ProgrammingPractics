#include "stdafx.h"
#include "Person.h"

using namespace std;

Person::Person(char Name[20], char Surname[20], int Age, enum Sex Sex)
{
	SetName(Name);
	SetSurname(Surname);
	SetAge(Age);
	SetSex(Sex);
}

void Person::SetName(char name[20])
{
	strcpy_s(Name, name);
}

void Person::SetSurname(char surname[20])
{
	strcpy_s(Surname, surname);
}

void Person::SetAge(int age)
{
	Age = age;
}

void Person::SetSex(enum Sex sex)
{
	Sex = sex;
}

char* Person::GetName()
{
	return Name;
}

char* Person::GetSurname()
{
	return Surname;
}

int Person::GetAge()
{
	return Age;
}

Sex Person::GetSex()
{
	return Sex;
}

Person* Person::Read()
{
	char tempName[20];
	char tempSurname[20];
	unsigned int tempAge;
	enum Sex tempSex;

	bool key = true;

	while (key)
	{
		cout << endl << "������� ���: ";
		cin >> tempName;
		key = !CheckChar(tempName);
	}

	key = true;

	while (key)
	{
		cout << endl << "������� �������: ";
		cin >> tempSurname;
		key = !CheckChar(tempSurname);
	}

	cout << endl << "������� ��� (0 - �������, 1 - �������): ";
	int n;
	do
	{
		n = EnterInteger();
	} while (n != 0 && n != 1);

	tempSex = enum Sex(n);

	cout << endl << "������� �������: ";
	tempAge = EnterInteger();

	return new Person(tempName, tempSurname, tempAge, tempSex);
}

void Person::Show(Person* person)
{
	cout << "���: " << person->Name << endl;
	cout << "�������: " << person->Surname << endl;
	cout << "�������: " << person->Age << endl;
	if (person->Sex)
	{
		cout << "���: Male" << endl;
	}
	else
	{
		cout << "���: Female" << endl;
	}
}

Person* Person::GetRandomPerson()
{
	const char* MaleNames[] = { "����", "�������", "����", "���������", "������", "�����", "�����", "������", "��������", "����������", "�������", "������" };
	const char* FemaleNames[] = { "�����", "����", "���������", "���������", "��������", "������", "�����", "������", "���������", "��������", "���������", "�����" };
	const char* MaleSurnames[] = { "�������", "�����������", "�������", "��������", "������", "�������", "��������", "������", "�������", "����������", "�������", "�������" };
	const char* FemaleSurnames[] = { "��������", "���������", "���������", "������", "������", "�������", "�������", "��������", "������", "��������", "�������", "��������" };

	char tempName[20];
	char tempSurname[20];
	int tempAge = 1 + rand() % 80;
	enum Sex tempSex = enum Sex(rand() % 2);

	if (tempSex)
	{
		strcpy_s(tempName, MaleNames[rand() % 12]);
		strcpy_s(tempSurname, MaleSurnames[rand() % 12]);
	}
	else
	{
		strcpy_s(tempName, FemaleNames[rand() % 12]);
		strcpy_s(tempSurname, FemaleSurnames[rand() % 12]);
	}
	return new Person(tempName, tempSurname, tempAge, tempSex);
}

bool Person::CheckChar(char name[])
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
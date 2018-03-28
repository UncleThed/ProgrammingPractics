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
		cout << endl << "Введите имя: ";
		cin >> tempName;
		key = !CheckChar(tempName);
	}

	key = true;

	while (key)
	{
		cout << endl << "Введите фамилию: ";
		cin >> tempSurname;
		key = !CheckChar(tempSurname);
	}

	cout << endl << "Введите пол (0 - женщина, 1 - мужчина): ";
	int n;
	do
	{
		n = EnterInteger();
	} while (n != 0 && n != 1);

	tempSex = enum Sex(n);

	cout << endl << "Введите возраст: ";
	tempAge = EnterInteger();

	return new Person(tempName, tempSurname, tempAge, tempSex);
}

void Person::Show(Person* person)
{
	cout << "Имя: " << person->Name << endl;
	cout << "Фамилию: " << person->Surname << endl;
	cout << "Возраст: " << person->Age << endl;
	if (person->Sex)
	{
		cout << "Пол: Male" << endl;
	}
	else
	{
		cout << "Пол: Female" << endl;
	}
}

Person* Person::GetRandomPerson()
{
	const char* MaleNames[] = { "Иван", "Дмитрий", "Олег", "Александр", "Андрей", "Денис", "Павел", "Сергей", "Владимир", "Константин", "Георгий", "Виктор" };
	const char* FemaleNames[] = { "Мария", "Анна", "Екатерина", "Елизавета", "Кристина", "Ксения", "Елена", "Галина", "Анастасия", "Виктория", "Валентина", "София" };
	const char* MaleSurnames[] = { "Макаров", "Достоевский", "Захаров", "Кузнецов", "Иванов", "Смирнов", "Васильев", "Петров", "Соколов", "Дубровский", "Новиков", "Борисов" };
	const char* FemaleSurnames[] = { "Дмириева", "Медведева", "Антоновна", "Жукова", "Орлова", "Козлова", "Волкова", "Морозова", "Быкова", "Миронова", "Власова", "Тихонова" };

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
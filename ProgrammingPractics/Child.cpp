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

	Concatenate(description, " лет, ");
	if (_sex)
	{
		Concatenate(description, " мальчик, ");
	}
	else
	{
		Concatenate(description, " девочка, ");
	}

	if (_mother == nullptr && _father == nullptr)
	{
		Concatenate(description, "родители не указаны.");
	}
	else if (_mother == nullptr)
	{
		Concatenate(description, "отец - ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, ".");
	}
	else if (_father == nullptr)
	{
		Concatenate(description, "мать - ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ".");
	}
	else
	{
		Concatenate(description, "родители: ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, " и ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ".");
	}

	return description;
}

Child* Child::GetRandom()
{
	const char* MaleNames[] = { "Иван", "Дмитрий", "Олег", "Александр", "Андрей", "Денис", "Павел", "Сергей", "Владимир", "Константин", "Георгий", "Виктор" };
	const char* FemaleNames[] = { "Мария", "Анна", "Екатерина", "Елизавета", "Кристина", "Ксения", "Елена", "Галина", "Анастасия", "Виктория", "Валентина", "София" };
	const char* MaleSurnames[] = { "Макаров", "Достоевский", "Захаров", "Кузнецов", "Иванов", "Смирнов", "Васильев", "Петров", "Соколов", "Дубровский", "Новиков", "Борисов" };
	const char* FemaleSurnames[] = { "Дмириева", "Медведева", "Антоновна", "Жукова", "Орлова", "Козлова", "Волкова", "Морозова", "Быкова", "Миронова", "Власова", "Тихонова" };

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
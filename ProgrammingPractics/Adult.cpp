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

	Concatenate(description, " лет, ");
	if (_sex)
	{
		Concatenate(description, "мужчина, ");
	}
	else
	{
		Concatenate(description, "женщина, ");
	}
	
	if (_marriedOn == nullptr)
	{
		Concatenate(description, "не в браке");
	}
	else
	{
		Concatenate(description, "в браке с ");
		Concatenate(description, _marriedOn->GetName());
		Concatenate(description, " ");
		Concatenate(description, _marriedOn->GetSurname());
	}

	if (*_workPlace == '\0')
	{
		Concatenate(description, ", безработный.");
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
	const char* MaleNames[] = { "Иван", "Дмитрий", "Олег", "Александр", "Андрей", "Денис", "Павел", "Сергей", "Владимир", "Константин", "Георгий", "Виктор" };
	const char* FemaleNames[] = { "Мария", "Анна", "Екатерина", "Елизавета", "Кристина", "Ксения", "Елена", "Галина", "Анастасия", "Виктория", "Валентина", "София" };
	const char* MaleSurnames[] = { "Макаров", "Достоевский", "Захаров", "Кузнецов", "Иванов", "Смирнов", "Васильев", "Петров", "Соколов", "Дубровский", "Новиков", "Борисов" };
	const char* FemaleSurnames[] = { "Дмириева", "Медведева", "Антоновна", "Жукова", "Орлова", "Козлова", "Волкова", "Морозова", "Быкова", "Миронова", "Власова", "Тихонова" };

	const char* WorkPlaces[] = { "программист", "продавец", "таксист", "юрист", "музыкант", "доктор", "учитель", "космонавт", "бухгалтер" };

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
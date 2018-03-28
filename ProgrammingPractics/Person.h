#pragma once

enum Sex
{
	Female,
	Male
};

class Person
{
	public:

		Person(char Name[20], char Surname[20], int Age, Sex Sex);

		void SetName(char name[20]);
		void SetSurname(char surname[20]);
		void SetAge(int age);
		void SetSex(Sex sex);

		char* GetName();
		char* GetSurname();
		int GetAge();
		Sex GetSex();

		Person* Read();
		void Show(Person* person);

		static Person* GetRandomPerson();

	private:

		bool CheckChar(char name[]);

		char Name[20];
		char Surname[20];
		int Age;
		Sex Sex;
};
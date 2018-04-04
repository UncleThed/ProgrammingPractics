#pragma once

enum Sex
{
	Female,
	Male
};

class Person
{
	public:
		Person() {};
		Person(char* name, char* surname, int age, Sex sex);

		void SetName(char* name);
		void SetSurname(char* surname);
		void SetAge(int age);
		void SetSex(Sex sex);

		char* GetName();
		char* GetSurname();
		int GetAge();
		Sex GetSex();

	private:
		char* _name;
		char* _surname;
		int _age;
		Sex _sex;
};
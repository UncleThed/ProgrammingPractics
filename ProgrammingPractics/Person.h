#pragma once
#include "strfunc.h"

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
		virtual void SetAge(int age);
		void SetSex(Sex sex);

		char* GetName();
		char* GetSurname();
		int GetAge();
		Sex GetSex();
		char* GetDescription();

		~Person();

	protected:
		char* _name;
		char* _surname;
		int _age;
		Sex _sex;
};
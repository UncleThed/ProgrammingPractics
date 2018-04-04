#pragma once
#include "Person.h"

class Child : public Person
{
	public:
		Child(char* name, char* surname, int age, Sex sex, Person* mother, Person* father);
		char* GetDescription();
		static Child* GetRandom();

		void SetAge(int age);
		void SetMother(Person* mother);
		void SetFather(Person* father);

		Person* GetMother();
		Person* GetFather();
	private:
		Person* _mother;
		Person* _father;
};
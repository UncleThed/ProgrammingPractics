#pragma once
#include "Person.h"

class Adult : public Person
{
	public:
		Adult(char* name, char* surname, int age, Sex sex, Person* marriedOn, char* workPlace);
		char* GetDescription();
		static Adult* GetRandom();

		void SetAge(int age);
		void SetMarriedOn(Person* marriedOn);
		void SetWorkPlace(char* workPlace);

		Person* GetMarriedOn();
		char* GetWorkPlace();

	private:
		Person* _marriedOn = nullptr;
		char* _workPlace = nullptr;
};
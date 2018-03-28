#pragma once
#include "Person.h"

class PersonListItem
{
	public:

		PersonListItem(Person* person);

		Person* GetValue();
		PersonListItem* Next = nullptr;
		PersonListItem* Prev = nullptr;

	private:

		Person* Value;
};
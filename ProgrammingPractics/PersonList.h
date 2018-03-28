#pragma once
#include "PersonListItem.h"

class PersonList
{
	private:

		PersonListItem* _head = nullptr;
		PersonListItem* _tail = nullptr;
		int _count = 0;

	public:

		PersonList() {};
		void Add(Person* person);
		Person* Find(int index);
		int IndexOf(Person* person);
		int GetCount();

		void Remove(Person* person);
		void RemoveAt(int index);

		void Show();
		void Clear();
};
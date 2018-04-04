#pragma once
#include "Person.h"
#include "Adult.h"
#include "Child.h"

class PersonList
{
	private:
		class PersonListItem
		{
			public:
				PersonListItem(Person* person)
				{
					_value = person;
				};

				Person* GetValue()
				{
					return _value;
				};

				PersonListItem* Next = nullptr;
				PersonListItem* Prev = nullptr;

			private:
				Person* _value;
		};

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

		void ShowDescriptions();
		void Show();

		void Clear();

		~PersonList()
		{
			Clear();
		};
};
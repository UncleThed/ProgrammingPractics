#include "stdafx.h"
#include "PersonList.h"

using namespace std;

void PersonList::Add(Person* person)
{
	PersonListItem* temp = new PersonListItem(person);
	if (!_head)
	{
		_head = temp;
	}
	else
	{
		temp->Prev = _tail;
		_tail->Next = temp;
	}
	_tail = temp;
	_count++;
}

Person* PersonList::Find(int index)
{
	if (index < 0)
	{
		return nullptr;
	}

	PersonListItem* searchedItem = _head;

	for (int i = 0; i < index; i++)
	{
		if (searchedItem->Next)
		{
			searchedItem = searchedItem->Next;
		}
	}
	return searchedItem->GetValue();
}

int PersonList::IndexOf(Person* person)
{
	PersonListItem* searchedPerson = _head;
	int index = 0;
	while (searchedPerson)
	{
		if (searchedPerson->GetValue() == person)
		{
			return index;
		}
		index++;
		searchedPerson = searchedPerson->Next;
	}
	return -1;
}

void PersonList::Remove(Person* person)
{
	PersonListItem* deletedItem = _head;

	if (person)
	{
		while (deletedItem->GetValue() != person)
		{
			if (!deletedItem->Next)
			{
				return;
			}
			deletedItem = deletedItem->Next;
		}
	}
	else
	{
		return;
	}

	if (deletedItem->Prev)
		deletedItem->Prev->Next = deletedItem->Next;
	else
		_head = deletedItem->Next;

	if (deletedItem->Next)
		deletedItem->Next->Prev = deletedItem->Prev;
	else
		_tail = deletedItem->Prev;

	delete deletedItem;
}

void PersonList::RemoveAt(int index)
{
	PersonListItem* deletedItem = _head;

	if (index >= 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (!deletedItem->Next)
			{
				return;
			}
			deletedItem = deletedItem->Next;
		}
	}
	else
	{
		return;
	}

	if (deletedItem->Prev)
		deletedItem->Prev->Next = deletedItem->Next;
	else
		_head = deletedItem->Next;

	if (deletedItem->Next)
		deletedItem->Next->Prev = deletedItem->Prev;
	else
		_tail = deletedItem->Prev;

	delete deletedItem;
}

void PersonList::Clear()
{
	PersonListItem* temp = _head;
	PersonListItem* tempNext;
	while (temp)
	{
		tempNext = temp->Next;
		delete temp;
		temp = tempNext;
	}
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}

int PersonList::GetCount()
{
	return _count;
}

void PersonList::Show()
{
	PersonListItem* temp = _head;

	if (temp)
	{
		cout << "Список:\n";
		cout << "----------------------------------------------------\n";
		cout.width(12); cout << "Индекс";
		cout.width(12); cout << "Имя";
		cout.width(12); cout << "Фамилия";
		cout.width(12); cout << "Пол\n";

		int index = 0;

		while (temp)
		{
			cout.width(12); cout << index++;
			cout.width(12); cout << temp->GetValue()->GetName();
			cout.width(12); cout << temp->GetValue()->GetSurname();
			cout.width(12);
			switch (temp->GetValue()->GetSex())
			{
			case 0:
				cout << "Женский\n";
				break;
			case 1:
				cout << "Мужской\n";
				break;
			}
			temp = temp->Next;
		}
	}
	else
	{
		cout << "Список пуст\n";
	}
	cout << endl;
}